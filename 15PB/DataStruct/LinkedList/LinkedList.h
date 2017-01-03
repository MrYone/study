#include "iostream"
#include "string.h"

using namespace std;

template <typename T>
class linkedlist{
   
    private:
    
        typedef struct st_linked{
            T linked_data;
            st_linked * addr;
            st_linked(){}
            st_linked(const T & data):lined_data(data),addr(nullptr){}   //结构体构造函数，初始化列表
        }st_linked, * st_plinked;

        st_plinked m_pLinkHead;
        int m_nlent;
        int m_ncurrlenth;

    public:

        linkedlist():m_pLinkHead(nullptr),m_nlent(),m_ncurrlenth(){}
        ~linkedlist(){}

        bool islinkedlistempty();       //  若链表为空，返回true，否则返回false
        bool clearlinkedlist();         //  将链表清空
        T findnum(int i);               //  将链表中的第i个元素返回给e
        int finddata(T e);              //  在链表中查找与给定值e相等的元素，成功返回序号，否则返回0
        bool insertdata(int i, T data);         //  在链表中的第i个位置中插入新元素
        bool deletedata(int i);         //  在链表中删除第i个位置的元素，并用e返回其值
        int lenth();                    //  返回链表L的元素个数
};

template <typename T>
bool linkedlist<T>::islinkedlistempty(){
    return (m_ncurrlenth == 0) ? true : false;
}

template <typename T>
bool linkedlist<T>::clearlinkedlist(){
    if(islinkedlistempty){
        return true;
    }    

    st_plinked temp = m_pLinkHead;
    
    while(temp->addr){
        m_pLinkHead = temp->addr;
        delete temp;
        temp = m_pLinkHead;
    }
    
    delete m_pLinkHead;
    m_pLinkHead = nullptr;
    m_ncurrlenth = 0;
    return true;
} 

template <typename T>
T linkedlist<T>::findnum(int i){
   if(i > m_ncurrlenth || i < 0){
       return false;
   } 

   st_plinked temp = m_pLinkHead;
   for(int n = 0; n < i - 1; ++n){
       temp = temp->addr;              
   }

   return temp->data;
}

template <typename T>
int linkedlist<T>::finddata(T e){
    if(islinkedlistempty()){
        return 0;
    }

    st_plinked temp = m_pLinkHead;
    for(int i = 0; temp->addr; ++i){
        if(temp->data == e){
            return i;
        }
        temp = temp->addr;
    }
}

template <typename T>
bool linkedlist<T>::insertdata(int i, T data){
    
    if(i > m_ncurrlenth || i < 0){
        return false;
    }

    if(m_pLinkHead == nullptr){
        m_pLinkHead = new st_linked;
        m_pLinkHead->addr = nullptr;
        m_pLinkHead->linked_data = data;
        m_ncurrlenth++;
        return true;
    }

    st_plinked pre = m_pLinkHead;
    st_plinked ptemp = new st_linked;
    ptemp->linked_data = data;
    ptemp->addr = nullptr;

    if(i == 0){
        ptemp->addr = m_pLinkHead;
        m_pLinkHead = ptemp;

        m_ncurrlenth++;
        return true;
    }

    for(int n = 0; n < i - 1; ++n){
        pre = pre->addr;
    }

    ptemp->add = pre->addr;
    pre->addr = ptemp;

    m_ncurrlenth++;
    return true;
}

template <typename T>
bool linkedlist<T>::deletedata(int i){
   if(i >= m_ncurrlenth || i < 0 || m_pLinkHead == nullptr){
       return false;
   }

   if(i == 0){
       st_plinkded temp = m_pLinkHead;
       m_pLinkHead = m_pLinkHead->addr;
       delete temp;
       m_ncurrlenth--;
       return true;
   }

   st_plinked temp = m_pLinkHead;
   st_plinked pre = nullptr;

   for(int n = 0; n < i - 1; ++n){
       temp = temp->addr;
   }

   pre = temp->addr;
   temp->addr = temp->addr->addr;
   delete pre;
   m_ncurrlenth--;
   return true;
}

template <typename T>
int linkedlist<T>::lenth(){
    return m_ncurrlenth;    
}