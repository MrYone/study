#include "iostream"
#include "string.h"

using namespace std;

template <typename T>
class Clist{
	public:
		
		Clist();
		~Clist(){
			if(!m_pList)
				delete[] m_pList; 
		}
		
		bool NewList(int lenth);	// 初始化操作，建立一个空的线性表
		bool IsListNull();			// 若线性表为空，返回ture，否返回false
		bool ClearList();			// 将线性表清空
		T FindNum(int i);			// 将线性表中的第i个位置元素值返回给e
		int FindData(T e);			// 在线性表中查找与给定值e相等的元素，
									// 成功返回序号，否则返回0
		bool Insert(int i, T e);	// 在线性表中的第i个位置中插入新元素
		T Delete(int i);			// 在线性表中删除第i个位置的元素，并用e返回其值
		int Lenth();				// 返回线性表L的元素个数

	private:
		
		T * m_pList;
		int m_nLenth;
		int m_nCurrLenth;
};
		
template <typename T>
Clist<T>::Clist() : m_pList(0), m_nLenth(1), m_nCurrLenth(0){}

template <typename T>
bool Clist<T>::NewList(int lenth){
	if(!IsListNull()){
		cout << "Exist List!" << endl;
		return false;
	}

	m_pList = new T[lenth + 1];
	m_nLenth = lenth + 1;
	m_nCurrLenth = 0;
	return true;
}

template <typename T>
bool Clist<T>::IsListNull(){
	if( m_nCurrLenth)
		return false;
	return true;
}

template <typename T>
bool Clist<T>::ClearList(){
	if(IsListNull())
		return true;

	m_nCurrLenth = 0;
}

template <typename T>
T Clist<T>::FindNum(int i){
	if(i > Lenth()){
		cout << "No This Data!" << endl;
		return 0;
	}

	return m_pList[i-1];
}

template <typename T>
int Clist<T>::FindData(T e){
	for(int i = 0; i <= m_nCurrLenth; ++i){
		if(e == m_pList[i])
			return i+1;
	}

	return 0;
}

template <typename T>
bool Clist<T>::Insert(int i, T e){
	if(m_nLenth == Lenth()){
		cout << "Linear is full, can't insert data!" << endl;
		return false;
	}
	
	if(i > Lenth()){
		cout << "Over flow! Now linear lenth is " << Lenth() << " !" << endl;
		cout << "You can only insert " << m_nLenth - Lenth() << " data." << endl;
		return false;
	}
	
	i = i - 1;

	for(int n = m_nCurrLenth; i <= n; --n) 
		m_pList[n + 1] = m_pList[n];
	
	m_nCurrLenth++;

	m_pList[i] = e;

	return true;
}

template <typename T>
T Clist<T>::Delete(int i){
	if(i > Lenth()){
		cout << "Over flow! No this Data." << endl;
		return false;
	}

	i = i - 1;
	
	T e = m_pList[i];

	for(int n = i; n <= m_nCurrLenth; ++n)
		m_pList[n] = m_pList[n + 1];

	m_nCurrLenth--;

	return e;
}

template <typename T>
int Clist<T>::Lenth(){
	return m_nCurrLenth + 1;
}



