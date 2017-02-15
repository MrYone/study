#include "iostream"
#include "stdio.h"

using namespace std;

int main(){		

	typedef unsigned int uint;
	typedef struct{
		uint posX;
		uint posY;
		uint ori;
		uint color;
		uint score;
		uint time;
		uint speed;
		uint num;
		char *tankbody;
	}Tank,*PTank;
	return 0;
}