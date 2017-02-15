#include "iostream"

using namespace std;

int main(){
	int n0,n1,n2;
	int *p0 = &n0,
		*p1 = &n1,
		*p2 = &n2;

	int temp ;

	cin >> *p0;
	cin >> *p1;
	cin >> *p2;

	for(int i = 3; i > 0; i--){
		if(*p0 > *p1){
			temp = *p0;
			*p0 = *p1;
			*p1 = temp;
		}
		if(*p1 > *p2){
			temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
	}

	cout << n0 << "<" << n1 << "<" << n2 << endl;


	return 0;
}