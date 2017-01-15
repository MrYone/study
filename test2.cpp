#include "iostream"

using namespace std;
// class CA
class CA{
	private:
		int m_a;
	
	public:
		CA():m_a(10){}
		void test();

};
//class CB
class CB{
	private:
		int m_a;
	
	public:
		CB():m_a(20){}
		void test();
};
//test CA
void CA::test(CA &obj){
	cout << obj.m_b << endl;
}
//test CB
void CB::test(CB &obj){
	cout << obj.m_a << endl;
}

int main(){
	CA obja;
	CB objb;

	obja.test();

	objb.test();
	
	return 0;
}