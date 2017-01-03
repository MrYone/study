#include "LinearList.h"
#include "iostream"

using namespace std;

int main(int argc, char * argv[]){
	Clist<int> list;
	Clist<char> charlist;

	
	list.NewList(10);
	cout << list.Lenth();
	
	

	return 0;
}
