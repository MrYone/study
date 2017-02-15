#include "iostream"

using namespace std;

void change(int array[], int n){
	int temp;
	for(int i = 0 ,j = n-1; i < n/2; i++, j--){
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
int main(){
	int arr[] = {0,1,2,3,4,5,6,7,8};
	change(arr,9);
	for (int i = 0; i < 9;i++)
		cout << arr[i] << endl;
	return 0;
}