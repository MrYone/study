#$language = "VBScript"
#$interface = "1.0"
crt.Screen.Synchronous = True

'------------------------------------------------------------------------------------------------------'

Const UserName1 = "", PassWord1 = ""
'设置第一套用户名和密码
'Const UserName2 = "", PassWord2 = "", EnablePassWD2 = ""
'设置第二套用户名和密码以及enable密码

Const LstFileLK = "C:\Users\admin\Desktop\scripts\list3.txt"
'设置地址表位置
Const CmdFileForHW = "C:\Users\admin\Desktop\scripts\HW.txt"
'设置华为命令表位置
Const CmdFileForCISCO = "C:\Users\admin\Desktop\scripts\CISCO.txt"
'设置思科命令表位置
Const LogFilLK = "C:\Users\admin\Desktop\scripts\LOG\" 
'设置回显保存的位置（此处只要设置保存到的文件夹位置，命令产生的回显会自动以IP.TXT保存在不同文件中）

Const Read = 1, Write = 2
'设置常量Read为1，Write为2


'以上为全局常量在整个程序中均有效

'------------------------------------------------------------------------------------------------------'

Dim data,IP

'------------------------------------------------------------------------------------------------------'

Sub Main
'主函数
	
	Dim fso, LstFile
	'定义两个变量（注：fso为局部变量仅在此函数中有效）
	
	Set fso = CreateObject("Scripting.FileSystemObject")
	'调用函数创建对象
	Set LstFile = fso.OpenTextFile(LstFileLK, Read, False)
	'调用函数创建对象的属性（读取地址表中的内容）
	
	Login(LstFile)
	'调用Login子函数，并将地址表中的内容传入
	
	Crt.Screen.Synchronous = False
	'Crt运行完毕
	
End Sub
'程序结束

'------------------------------------------------------------------------------------------------------'

Sub Login(LstFile)
'Login子函数（接收主函数传递的内容）
	
	Dim SwitchKey
		
	data = date()
		
	Do While LstFile.AtEndOfStream <> True
	'循环读入地址表中的内容直到结束
	On Error Resume Next
	
		IP = LstFile.ReadLine
		'读入地址表中的第一行内容
		Crt.Session.LogFileName = LogFileLK & data & "\" & IP & ".txt"
		'创建回显保存的文件名（IP.TXT）
		
		Crt.Session.Log(True)
		
		crt.Session.Connect "/SSH2 /L " & UserName1 & " /PASSWORD " & PassWord1 & " " & IP 
		
		On Error Resume Next
	
		SwitchKey = Crt.Screen.WaitForStrings("<",">" ,10)
			
		Select Case SwitchKey
			
			Case 1
				
				Crt.Screen.Send "su" & vbCr
				
				If Crt.Screen.WaitForString ("Password:",2) then
					
					Crt.Screen.Send PassWord1 & vbCr
					
				end if
				
			Case 2 
				
				Crt.Screen.Send "enable" & vbCr
				Crt.Screen.WaitForString "Password: "
				Crt.Screen.Send PassWord1 & vbCr
				
			Case Else 
				
				Crt.Session.LogFileName = LogFileLK & data & "\" & "Fail" & IP & ".txt"
				Crt.Session.Log(false)
				crt.Session.Disconnect
					
		End Select
	    
		RunCommand(SwitchKey)
		'调用RunCommand子函数
		
	Loop
	'循环结束
	
End Sub
'返回主函数

'------------------------------------------------------------------------------------------------------'

Sub RunCommand(SwitchKey)
'RunCommand子函数
	
	Dim fso, CmdFile, CMD
	'此处fso变量属于局部变量，所以不会和主函数中的fso变量冲突
	
	Set fso = CreateObject("Scripting.FileSystemObject")
	'创建对象
	
	Select Case SwitchKey
	
		Case 1
			
			Set CmdFile = fso.OpenTextFile(CmdFileForHW, Read, False)
			
			Crt.Session.Log(false)
			Crt.Session.LogFileName = LogFileLK & data & "\" & IP & ".txt"
			Crt.Session.Log(True)
			
		Case 2 
		
			Set CmdFile = fso.OpenTextFile(CmdFileForCISCO, Read, False)
		
	End Select

	Do While CmdFile.AtEndOfStream <> True
	'循环执行命令表中的命令直到结束
		
		CMD = CmdFile.ReadLine
		crt.Screen.Send CMD & vbcr
		'执行命令表中的命令
		
		Do While (crt.Screen.WaitForString("More",3) = True)
		
			crt.Screen.Send(" ")
		
		Loop 
		
		crt.Screen.Send chr(13)
		
	Loop
	'循环结束
	
'	GetName(SwitchKey)
	
	Crt.Session.Log(false)
	
	crt.Session.Disconnect
	'关闭CRT对话框
	
End Sub
'返回Login子函数

'------------------------------------------------------------------------------------------------------'


'Yone 2016.7.5编写
'版本1.2.2
'SSH2
