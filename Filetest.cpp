#include "fstream"
#include "iostream"

using namespace std;


int main(){
	ofstream fout;
	string filename;

	cin >> filename;

	fout.open(filename);

	fout << filename;

	fout.close();
	
	return 0;

}