#include "iostream"
#include "string.h"

template <typename T>
class BinaryTree{
	
	private:

		typedef struct _tree{
			T st_data;
			_tree * pLeft;
			_tree * pRight;
			_tree(){}
			_tree(const T & data):st_data(data),pLeft(nullptr),pRight(nullptr){}
		}Btree, * pBtree;

		ptree m_ptreeroot;

	public:

		BinaryTree(){}
		~BinaryTree(){}

		bool insertdata();
		bool deletedata();
		void pre_order();
		void in_order();
		void post_order();
		bool clearTree();



};

template <typename T>














