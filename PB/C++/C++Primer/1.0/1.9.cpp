#include "iostream"
using namespace std;

int main(){
	int i = 50;
	int n = 50;

	while(n <= 100){
		n++;
		i = n + i;
	}

	cout << "50 ~ 100  : " << i << endl;
	return 0;
}
