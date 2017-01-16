#include "iostream"

using namespace std;

int main(){
	char *cArr[] = {
		"Hello",
		"15pb",
		"Change",
		"World"
	};
	
	char **c = cArr;
	for (int i = 0 ; i < 4; i++)
	cout << c[i] << endl;
	return 0;
}