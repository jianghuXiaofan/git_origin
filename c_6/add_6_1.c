#include <stdio.h>

int main(int argc, char **argv)
{
	int x = 3;
	int y = 2;
	x *= y + 8;//x = x * (y + 8) 
	printf("%d",x);
	return 0;
}
