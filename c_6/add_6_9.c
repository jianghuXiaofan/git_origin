#include <stdio.h>

int main(int argc, char **argv)
{
	int x = 12,n = 5; 
	x%=(n%=2);
	//printf("%d\n",(x%=(n%=2)));
	printf("%d\n",x);
	return 0;
}
