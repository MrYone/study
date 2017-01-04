#include <curses.h>
#include "time.h"
#include "stdlib.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int mygetch( ) {
	struct termios oldt,
				   newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}
int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;
		   
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
					   
	ch = getchar();
						 
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
							 
	if(ch != EOF){
		ungetc(ch, stdin);
		return 1;
	}
							   
	return 0;
}

char UserEnter(){
	int time = clock();
	int c;
	int white = 10000000;

	printf("i white you %d sec to enter something\n",white);
	while(1){
		if(kbhit())
			return mygetch();
		if(clock() - time > white)
			return '\0';
	}
}


int main (){	
	char c;
	if(c = UserEnter())
		printf("\nUser enter key is : %c\n",c);
	else
		printf("\nUser do not enter something!\n");
	return 0;
}

