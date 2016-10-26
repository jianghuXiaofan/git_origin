#include <stdio.h>

int main(int argc, char **argv)
{
	int w=1,x=2,y=3,z=4;
	printf("%d\n",(w<x?w:y<z?y:z));
	return 0;
}
