#include "iostream"

using namespace std;

int main(){
	int arr[40][40] = {0};
	for (int i = 0; i < 40; i++)
		arr[i][39] = arr[i][0] = arr[39][i] = arr[0][i] = 1;
	
	for(int y = 0; y < 40; y++){
		for (int x = 0; x < 40; x++)
			cout << (arr[y][x] ? "□" : " "); 
		cout << endl;
	}

	return 0;
}