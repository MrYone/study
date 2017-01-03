#include "iostream"
using namespace std;

class test{
	public:

	test():a(10),b(20){cout << "test()"<< endl;}

	~test(){cout << "~test()"<< endl;}

//	test(const test&){cout << "copy test()1" << endl;}

	test(const test & obj){
		cout << "copy test()2"<< endl;
		a = obj.a;
		b = obj.b;
	}

	int a;
	int b;

	//private:
	
	test operator+(test &obj){
		 test sum;
		 sum.a = a + obj.a;
		 sum.b = b + obj.b;
		 return sum;
	}





};



int main(){
	test a,b,c,sum;
	sum = a+b+c;

	cout << sum.a<< endl<<(a+b+c).b<< endl;

	return 0;
}
