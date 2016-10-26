#include <stdio.h>

int main(int argc, char **argv)
{
	int w=4,x=3,y=2,z=1;
	printf("%d\n",(w < x ? w : z < y ? z : x));
	
	return 0;
}
