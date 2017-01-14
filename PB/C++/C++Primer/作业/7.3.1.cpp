#include "iostream"

using namespace std;

const int MAX = 100;
int main(){
	char UserEnter[MAX];
	//int Length;

	cin.getline(UserEnter,MAX);
	cout << strlen(UserEnter) << endl;
	for(int i = strlen(UserEnter)-1;i >= 0 ; i --){
		if((UserEnter[i]>='a')&&(UserEnter[i]<='z')||(UserEnter[i]>='A')&&(UserEnter[i]<='Z'))
			cout << UserEnter[i];
		//cout << endl;
	}
	cout << endl;
	//cout << UserEnter << endl;
	return 0;
}