#!/usr/local/bin/python3.6
# -*- coding: UTF-8 -*-


import os
import sys
import os.path
import random
import shutil
import io
import requests
sys.path.append('C:\libsvm-3.21\python')
from PIL import Image,ImageEnhance,ImageFilter
from svmutil import *





class AttackVerificationCode(object):
    def __init__(self):
        None


    def Step1_Downloads_PIC(self,strImgURL,strImgType,strPath,strName):
        """
        验证码下载函数：用于批量下载目标站点的验证码
        strImgURL： 验证码图片链接
        strImgType：验证码图片类型
        strPath：保存验证码图片目录
        strName：保存验证码图片文件名
        示例：Step1_Downloads_PIC('http://www.xx.com/123','.bmp','d:/TestDir/','123')
        """
        # 1. 以二进制流的方式发送一个Get请求，将stream=True，在读取完所有数据前不断开链接
        rReq = requests.get(strImgURL, stream=True)
        # 2. 尝试保存图片
        with open(strPath+strName+strImgType, 'wb') as fpPIC:
            # 一次读取1024Byte的内容到byChunk中，如果读取不完则循环读取
            for byChunk in rReq.iter_content(chunk_size=1024):
                    fpPIC.write(byChunk)
                    fpPIC.flush()
        fpPIC.close()


    def Step2_DismantlingImg(self, strInputDir, Left, Upper, Right, Lower, strOutPutDir):
        """
        图片处理拆解函数：用于将一个目录下的所有文件按照指定大小切分，并保存在输出文件夹
        strInputDir： 存放待拆分图片的文件夹
        Left：第一个验证码字符的最左边(像素)
        Upper：第一个验证码字符的最上边(像素)
        Right：第一个验证码字符的最右边(像素)
        Lower：第一个验证码字符的最下边(像素)
        strOutPutDir：输出切割好的文件
        示例：Step2_DismantlingImg('D:/123',6,3,19,18,'D:/456')
        """
        nCount = 0
        for ParentPath,DirNames,FileNames in os.walk(strInputDir):
            for i in FileNames:
                strFullPath = os.path.join(ParentPath,i)            # 图片文件路径信息
                imgBinImg   = self.__BinaryzationImg__(strFullPath) # 二值化处理
                imgClrImg   = self.__ClearNoise__(imgBinImg)        # 清理图片噪点
                ImgList     = self.__GetCropImgs__(imgClrImg,Left, Upper, Right, Lower) # 切割图片
                for img in ImgList: # 保存切割好的图片
                    strImgName = "%04d%04d.png" % (nCount,random.randint(0,9999))
                    strImgPath = os.path.join(strOutPutDir,strImgName)
                    img.save(strImgPath)
                    nCount += 1


    def Step3_OutPutVectorData(self, strID, strMaterialDir, strOutPath):
        """
        输出SVM向量数据函数：用于给一个目录下的所有文件按照指定规则生成特征值，并按照符合SVM向量的格式保存在输出文件中
        strInputDir： 存放待拆分图片的文件夹
        strID：SVM向量ID，必须为阿拉伯数字的字符串，可以随意定义，自己知道是什么意思即可
        strMaterialDir：原材料文件夹，指向已经切分好、并人工分好类的验证码文件夹
        strOutPath：输出SVM向量文件
        示例：Step3_OutPutVectorData('15','D:/123','D:/456/Vector.txt')
        """
        for ParentPath,DirNames,FileNames in os.walk(strMaterialDir):
            with open(strOutPath, 'a') as fpFea:
                for fp in FileNames:
                    strFullPath = os.path.join(ParentPath,fp)          # 图片文件路径信息
                    imgOriImg = Image.open(strFullPath)                # 打开图片
                    FeatureList = self.__GetFeature__(imgOriImg,14,13) # 生成特征值
                    nCount = 1
                    strFeature = strID+' ' # 制造符合SVM向量格式的文件内容
                    for i in FeatureList:
                        strFeature = '%s%d:%d ' % (strFeature,nCount,i)
                        nCount+=1
                    fpFea.write(strFeature+'\n')
                    fpFea.flush()
            fpFea.close()


    def Step4_TrainSvmModel(self,strProblemPath,strModelPath):
        """
        训练支持向量机模型文件：使用向量结果训练SVM生成支持向量机模型文件
        strProblemPath：SVM向量文件
        strModelPath：支持向量机模型文件（训练结果）
        示例：Step4_TrainSvmModel('D:/123/Vector.txt','D:/456/Model.txt')
        """
        Y,X = svm_read_problem(strProblemPath) # 用SVM向量文件得出 Y,X 二维数据
        Model = svm_train(Y,X)                 # 使用得出的二维数据训练SVM得出支持向量机模型
        svm_save_model(strModelPath, Model)    # 将支持向量机模型保存为文件


    def Step5_TestSvm(self,strURL,strOutDir,strImgType,strModelPath, Left, Upper, Right, Lower):
        """
        测试SVM：直接在目标网站读取验证码，识别后保存到指定目录
        strURL： 验证码网址
        strOutDir：保存识别结果的目录
        strImgType：验证码图片格式
        strModelPath：支持向量机模型文件路径
        Left：第一个验证码字符的最左边(像素)
        Upper：第一个验证码字符的最上边(像素)
        Right：第一个验证码字符的最右边(像素)
        Lower：第一个验证码字符的最下边(像素)
        示例：Step5_TestSvm('http://www.xxx.com/123/','D:/123','.png','D:/456/Model.txt',6,3,19,18)
        """
        # 1. 创建临时目录与常用路径名
        try:
            os.mkdir('D:/TestSvmTemp/')
            os.mkdir('D:/TestSvmTemp/Step_1/')
            os.mkdir('D:/TestSvmTemp/Step_2/')
            os.mkdir('D:/TestSvmTemp/Step_3/')
        except:
            None
        strVefCodeImg = 'D:/TestSvmTemp/Step_1/VefCodeImg.png'
        strVectorPath = 'D:/TestSvmTemp/Vector.txt'
        # 2. 下载验证码图片
        self.Step1_Downloads_PIC(strURL,strImgType,'D:/TestSvmTemp/Step_1/','VefCodeImg')
        # 3. 处理验证码图片并分割
        self.Step2_DismantlingImg('D:/TestSvmTemp/Step_1/',Left, Upper, Right, Lower,'D:/TestSvmTemp/Step_2/')
        # 4. 训练SVM为待识别的验证码生成向量文件
        self.Step3_OutPutVectorData('0','D:/TestSvmTemp/Step_2/',strVectorPath)
        # 5. 使用训练好的支持向量机模型文件分析待识别验证码的向量信息，以此得出识别结果
        pLabel = self.__SvmModelTest__(strVectorPath,strModelPath)
        # 6. 将识别结果的float型转换为字符串
        Char1 = chr(int(pLabel[0]))
        Char2 = chr(int(pLabel[1]))
        Char3 = chr(int(pLabel[2]))
        Char4 = chr(int(pLabel[3]))
        if pLabel[0]<10: Char1 = '%s'%int(pLabel[0])
        if pLabel[1]<10: Char2 = '%s'%int(pLabel[1])
        if pLabel[2]<10: Char3 = '%s'%int(pLabel[2])
        if pLabel[3]<10: Char4 = '%s'%int(pLabel[3])
        strOutFile = Char1 + Char2 + Char3 + Char4
        # 7. 将验证码重命名为其图片文字内容，并保存到目标文件夹
        strOutImgPath = os.path.join(strOutDir,strOutFile+strImgType)
        shutil.copyfile(strVefCodeImg,strOutImgPath)
        # 8. 强制删除临时目录（包括文件）
        __import__('shutil').rmtree('D:/TestSvmTemp/')
        return pLabel


    def __BinaryzationImg__(self, strImgPath):
        imgOriImg = Image.open(strImgPath)
        pocEnhance = ImageEnhance.Contrast(imgOriImg)   # 增加对比度
        imgOriImg = pocEnhance.enhance(2.0)             # 增加200%对比度
        pocEnhance = ImageEnhance.Sharpness(imgOriImg)  # 锐化
        imgOriImg = pocEnhance.enhance(2.0)             # 锐化200%
        pocEnhance = ImageEnhance.Brightness(imgOriImg) # 增加亮度
        imgOriImg = pocEnhance.enhance(2.0)             # 增加200%对亮度
        imgGryImg = imgOriImg.convert('L').filter(ImageFilter.DETAIL) # 滤镜效果
        imgBinImg = imgOriImg.convert('1')              # 转为黑白图片（二值化）
        return imgBinImg


    def __ClearNoise__(self,imgBinImg):
        for x in range(1,(imgBinImg.size[0]-1)):
            for y in range(1,(imgBinImg.size[1]-1)):
                # 如果中心点为黑色，周围8点皆为白色，此点为噪点，置为白色
                if imgBinImg.getpixel((x,y))==0 \
                    and imgBinImg.getpixel(((x-1),(y+1)))==255 \
                    and imgBinImg.getpixel(((x-1), y   ))==255 \
                    and imgBinImg.getpixel(((x-1),(y-1)))==255 \
                    and imgBinImg.getpixel(((x+1),(y+1)))==255 \
                    and imgBinImg.getpixel(((x+1), y   ))==255 \
                    and imgBinImg.getpixel(((x+1),(y-1)))==255 \
                    and imgBinImg.getpixel(( x   ,(y+1)))==255 \
                    and imgBinImg.getpixel(( x   ,(y-1)))==255:
                    imgBinImg.putpixel([x,y],255) # 此点为噪点，置为白色
        return imgBinImg


    def  __GetCropImgs__(self, imgClrImg, Left, Upper, Right, Lower):
        ImgList = []
        # 循环4次（因为验证码为4个字符），并根据第一个字符大小依次切割后面的字符
        for i in range(4):
            x = Left + i*(Right-Left)
            y = Upper
            SubImg = imgClrImg.crop((x, y, x+(Right-Left), y+(Lower-Upper)))
            ImgList.append(SubImg) # 将切割好的图片对象保存到列表中
        return ImgList


    def __GetFeature__(self, imgCropImg, nImgHeight, nImgWidth):
        """
        特征提取：
            特征提取是SVM最为重要的一环，特征提取的是否合理、准确，是否能尽可能的降低干扰，将直接决定SVM的工作准确率。
        本项目只是用简单的统计方式，先从第一行像素开始，统计有多少黑色像素点，依次统计并记录，然后再从第一列像素开始，
        统计每一列分别有多少黑色像素点，最后使用其他函数将统计结果转换为SVM能接受的向量文件，并进行下一步训练。
        """
        PixelCountList = []
        for y in range(nImgHeight):
            CountX = 0
            for x in range(nImgWidth):
                if imgCropImg.getpixel((x, y)) == 0:  # 黑色点
                    CountX += 1
            PixelCountList.append(CountX)
        for x in range(nImgWidth):
            CountY = 0
            for y in range(nImgHeight):
                if imgCropImg.getpixel((x, y)) == 0:  # 黑色点
                    CountY += 1
            PixelCountList.append(CountY)
        return PixelCountList


    def __SvmModelTest__(self,strProblemPath,strModelPath):
        TestY, TestX = svm_read_problem(strProblemPath)       # 用SVM向量文件得出 Y,X 二维数据
        Model        = svm_load_model(strModelPath)           # 使用得出的二维数据训练SVM得出支持向量机模型
        pLabel, pAcc, pVal = svm_predict(TestY, TestX, Model) # 匹配识别（p_label即为识别结果）
        return pLabel





objAtkVefCode = AttackVerificationCode()

for i in range(1,51):
    objAtkVefCode.Step5_TestSvm('http://www.bjgjj.gov.cn/wsyw/servlet/PicCheckCode1','D:/Dir/Test/','.png','E:/MyWork/01_Teching/11_Common_Courses/01_Hacking_diy/step_5/Model.txt',6,3,19,18)

