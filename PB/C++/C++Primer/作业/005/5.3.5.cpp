#include "iostream"
#include "stdio.h"
using namespace std;

int main(){
	typedef struct _STUINFO{
		int nNum = 0;
		char szName[20] = {0};
		int nScore = 0;
		//_STUINFO():nNum(0),nScore(0){}
	}STUINFO,*PSTUINFO;

	STUINFO Sstu;
	
	Sstu.nNum = 25;
	strcpy(Sstu.szName,"liming");
	Sstu.nScore = 88;
	printf("[%d]%t[%s]%t[%d]\n",Sstu.nNum,Sstu.szName,Sstu.nScore);

	return 0;
}