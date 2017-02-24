#include "iostream"

using namespace std;

using uint = unsigned int;

typedef struct BookInfo{
	char *BookName;
	char *Author;
	int Price;	
}BookInfo,*pBookInfo;

bool initBook(pBookInfo &pBook,uint nCount){
	pBook = new BookInfo[nCount];


	for(int i = 0; i < nCount; i++){

		pBook[i].BookName; 	
	}
	return true;	
}


int main(){
	pBookInfo pBook = NULL;
	initBook(pBook,10);



	
	return 0;
}