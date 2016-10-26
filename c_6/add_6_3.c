#include <stdio.h>

int main(int argc, char **argv)
{
	char ch = 'a' + '8' - '3';
	//a     110 0001
	//'8' +  11 1001 
	//    =1001 1010  
	//    -  11 0100
	//    = 110 0110  (64+32+4+2) =102
	printf("'%c' %d\n",ch, ch);
	return 0;
}
