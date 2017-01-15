#include "iostream"

using namespace std;
// class CA
//template <class T>
class CA{
	private:
		int m_a;
	
	public:
		CA():m_a(10){}

		template <typename T>
		friend void test(T &obj);

};
//class CB
//template <class T>
class CB{
	private:
		int m_a;
	
	public:
		CB():m_a(20){}

		template <typename T>
		friend void test(T &obj);
};
//test
template <class T>
void test(T &obj){
	cout << obj.m_a << endl;
}

int main(){
	CA obja;
	CB objb;

	test(obja);

	test(objb);
	
	return 0;
}