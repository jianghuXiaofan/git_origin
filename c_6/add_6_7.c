#include <stdio.h>

int main(int argc, char **argv)
{
	int x = 10;
//	x += x -= x - x;
	printf("%d\n",x += x -= x-x); 
	return 0;
}
