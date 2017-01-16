#include "iostream"
#include "string"
using namespace std;

int main(){
	string s;
	getline(cin,s);
	cout << s.size() << endl;
	cout << s[0] << endl;
	cout << s << endl;	
	cout << &s << endl;
	return 0;
}