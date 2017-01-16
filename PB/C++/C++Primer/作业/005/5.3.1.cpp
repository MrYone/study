#include "iostream"
#define LENTH 10
using namespace std;

int main(){
	int arr[LENTH] = {0};
	int *p = arr;
	for(int i = 0; i < LENTH; i++)
	cin >> arr[i];
	for(int i = 0; i < LENTH; i++)
	cout << *(p+i) << endl;
	return 0;
}