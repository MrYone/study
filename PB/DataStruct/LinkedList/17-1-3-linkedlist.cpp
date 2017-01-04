//ADT	linkedlist

//data

//线性表的数据对象集合为（a1,a2,a3,.....,an),
//每个元素的类型均为datatype。
//其中除第一个元素a1外，
//每一个元素有且只有一个直接前驱元素，
//除了最后一个元素an外，
//每一个元素有且只有一个后继元素。
//数据元素之间的关系是一一对应的关系
//
//opretion
//
//InitList(*L);			初始化操作，建立一个空的线性表L
//ListEmpty(L);			若线性表为空，返回ture，否则返回false
//ClearList(*L);		清空线性表
//GetElem(L,i,*e);		将线性表中的第i个位置元素返回给e
//LocateElem(L,e);		在线性表L中查找与给定值e相等的元素，
//						如果查找成功，返回该元素在表中序号表示成功;
//						否则，返回0表示失败。
//ListInsert(*L,i,e);	在线性表L中的第i个位置插入新元素e
//ListDelete(*L,i,*e);	删除线性表L中第i个位置的元素，并用e返回其值
//ListLength(L);		返回线性表L的元素个数
//
//endADT




#include "iostream"
#include "string.h"

class ClinkedList{
	private:

//		static int MAXSIZE;

		typedef int ElemType;

		typedef struct{
			//ElemType data[MAXSIZE];
			ElemType data[20];
			int Length;
		}SqList;

	public:

		bool InitList(ElemType *L);
		bool ListEmpty(ElemType L);
		bool ClearList(ElemType *L);
		bool GetElem(ElemType L,int i,int *e);
		int LocateElem(ElemType L,int e);
		bool ListInsert(ElemType *L,int i,int e);
		bool ListDelete(ElemType *L,int i,int *e);
		int ListLenght(ElemType L);

};

//ClinkedList::static int MAXSIZE = 20;
bool ClinkedList::InitList(ElemType *L){
}
bool ClinkedList::ListEmpty(ElemType L){
}
bool ClinkedList::ClearList(ElemType *L){
}
bool ClinkedList::GetElem(ElemType L,int i,int *e){
}
int ClinkedList::LocateElem(ElemType L,int e){
}
bool ClinkedList::ListInsert(ElemType *L,int i,int e){
}
bool ClinkedList::ListDelete(ElemType *L,int i,int *e){
}
int ClinkedList::ListLenght(ElemType L){
}

int main(){
	return 0;
}












