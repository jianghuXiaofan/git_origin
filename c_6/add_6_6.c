#include <stdio.h>

int main(int argc, char **argv)
{
	int p = 30;
	printf("%d\n",( p / 3 > 0 ? p / 10 : p % 3));
	
	return 0;
}
