#include "iostream"
using namespace std;

int main(){
	int sum = 0, var;
	cout << "enter some num , take  esc and enter end this!" << endl;
	while(cin >> var)
		sum += var;
	cout << "add all of num is : " << sum << endl;
	return 0;
}
