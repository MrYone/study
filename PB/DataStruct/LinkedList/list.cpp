#define LI_SUCCESS  0
#define LI_WRONG_LOG    1
#define LI_EMPTY    2

#include "list.h"
#include "stream.h"
template <typename T_LK>
CLinkList<T_LK>::CLinkList() : m_pHead(mullptr), m_nLenth(0){}

template <typename T_LK>
CLinkList<T_LK>::~CLinkList(){}

template <typename T_LK>
bool CLinkList<T_LK>::IsEmpty(){
	return (m_dwLenth == 0) ? true : false;
}

template <typename T_LK>
DWORD CLinkList<T_LK>::Lenth(){
	return m_dwLenth;
}

template <typename T_LK>
void CLinkList<T_LK>::clear(){
	//	判断链表是否为空
	if((nullptr == m_Head) || 0 == m_dwLenth){
		return ;
	}
	//	链表不为空，开始清空
	PNODE tmep = m_Head;
	while(!temp->pNext){
		m_Head = temp->pNext;
		delete temp;
		temp = m_Head;
	}
	//	删除最后一个节点，并将链表长度置为0
	delete m_Head;
	m_Head = nullptr;
	m_dwLenth = 0;
}

template <typename T_LK>
OperCode CLinkList<T_LK>::GetEle(_In_ DWORD Index, _Out_ T_LK & Data){
	//	判断链表是否为空
	if((nullptr == m_Head) || 0 == m_dwLenth) {
		return LK_BUFFER_IS_EMPTY;
	}
	//	判断索引是否超出范围
	if((0 == Index) || Index > m_dwLenth){
		return LK_INDEX_IS_WRONG;
	}
	//	循环开始查找索引点
	PNODE ptemp = m_Head;
	for(DWORD i = 1; i < Index; i++){
		ptmep = ptemp->pNext;
	}
	//	将元素赋值到传出元素
	memcpy_s(&Data, sizeof(T_LK), & ptemp->Data, sizeof(T_LK));
	return LK_SUCCESS;
}

template <typename T_LK>
DWORD CLinkList<T_LK>::GetLoc(_In_ T_LK Data){
	//	判断链表是否为空
	if((nullptr == m_Head) || 0 == m_dwLenth){
		return 0;
	}
	//	循环匹配链表内容，匹配到后返回i值
	PNODE ptemp = m_Head;
	for(DWORD i = 1; i <= m_dwLenth; i++){
		if(!memcmp(&Data, &ptemp->Data, sizeof(T_LK))){
			return i;
		}
		ptemp = ptemp->pNext;
	}
	//	没有找到
	return 0;
}

template <typename T_LK>
bool CLinkList<T_LK>::ListInsert(int nLoc, int nData, int & nError){
	//	判断插入位置是否越界
	if(nLoc > m_nLenth){
		nError = LI_WRONG_LOC;
		return false;
	}
	//	判断头节点是否为空，为空的话，直接在头节点插入数据
	if(m_pHead == nullptr){
		m_pHead = new NODE;
		m_pHead->pNext = nullptr;
		m_pHead->Data = nData;
		nError = LI_SUCCESS;
		m_nLenth++;
		return true;
	}
	//	找到插入位置
	//	找到插入位置的前一个节点
	PNODE pre = m_pHead;
	PNODE ptemp = new NODE;
	ptemp->Data = nData;
	ptemp->pNext = nullptr;
	//	判断是否是向头节点之前插入，处理特殊情况
	if(nLoc == 0){
		ptemp->pNext = m_pHead;
		m_pHead = ptemp;

		nError = LI_SUCCESS;
		m_nLenth++;
		return true;
	}
	//	正常情况
	for(int i = 0; i < nLoc - 1; i++)
		pre = pre->pNext;
	//	执行插入操作
	ptemp->pNext = pre->pNext;
	pre->pNext = ptemp;
	//	插入成功，长度自增并返回
	nError = LI_SUCCESS;
	m_nLenth++;
	return true;
	
}

template <typename T_LK>
bool CLinkList<T_LK>::ListDelete(int nLoc, int & nData, int & nError){
	//	判断链表是不是空的
	if(m_pHead == nullptr){
		nError = LI_EMPTY;
		return false;
	}
	//	判断删除的位置是否是错误的
	if(nLoc >= m_nLenth){
		nError = LI_WRONG_LOG;
		return false;
	}
	//	找到要删除的位置
	//	要删除的是头节点
	if(nLoc == 0){
		//	给传出数据赋值
		nData = m_pHead->Data;
		//	用一个临时变量存储要被释放的头节点
		PNODE ptemp = pHead;
		//	头节点指针指向下一个节点
		m_pHead = m_pHead->pNext;
		//	释放被删除的节点
		delete ptemp;
		//	处理后面的事情
		ptemp = nullptr;
		m_nLenth--;
		nError = LI_SUCCESS;
		return true;
	}
	//	正常情况，需要循环找到被删除节点的前一个节点
	PNODE pre = m_pHead;
	PNODE ptemp = nullptr;
	for(int i = 0; i < nLoc - 1; i++){
		pre = pre->pNext;
	}
	//	开始删除
	//	将要被删除的节点的地址存储到临时变量中
	ptemp = pre->pNext;
	//	为传出数据赋值
	nData = ptemp->Data;
	//	将被删除的前一个节点和被删除的后一个节点连起来
	pre->pNext = pre->pNext->pNext;
	delete ptemp;
	ptemp = nullptr;
	//	删除成功，填写错误码，长度自减并返回
	m_nLenth--;
	nError = LI_SUCCESS;
	return true;
}
