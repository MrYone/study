#include "iostream"

using namespace std;

int main(int argc, char * argv[]){

//	cout << argc << endl;	//argc表示有几个参数，包括命令本身
	
//	cout << argv[0] << endl;	//argv[]存储的是输入的命令和参数，argv[0]表示命令本身，argv[1]表示第一个参数

	for(int i = 1; i < argc; ++i)
		cout << argv[i] << endl;


	return 0;

}

