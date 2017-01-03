#define LI_SUCCESS	0
#define LI_WRONG_LOG	1
#define LI_EMPTY	2

template <typename T_LK>

class CLinkList{
	public:
		CLinkList();
		~CLinkList();

		typedef struct _NODE{		//	节点结构体
			int Data;				//	节点中的数据部分
			_NODE * pNext;			//	指向下一个节点的指针
		}NODE, *PNODE;

		bool IsEmpty();				//	判断链表是否为空

		DWORD Lenth();				//	返回链表的长度

		void clear();				//	清空链表

		OperCode GetEle(			//	获取索引处内容
				_In_ DWORD Index,	//	索引值
				_Out_ T_LK & Date	//	获取值的内容
				);

		DWORD GetLoc(				//	获取内容为Data的第一个元素的位置
				_In_ T_LK Data		//	要获取的内容
				);

		bool ListInsert(			//	在链表的某一个位置插入一个节点
				int nLoc,			//	要插入的位置
				int nData,			//	要插入的数据
				int & nError		//	用于获得一个错误码
				);

		bool ListDelete(			//	在链表的某一个位置删除一个节点，并返回被删掉的数据
				int nLoc,			//	要删除的位置
				int & nData,		//	要删除的数据
				int & nError		//	用于获得一个错误码
				);

	private:
		PNODE m_pHead;				//	头节点指针
		int m_nLenth;				//
};

