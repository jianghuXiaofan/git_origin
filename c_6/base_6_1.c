#include <stdio.h>

int main(int argc, char **argv)
{
	int a;

	printf("int在内存中占的字节数：\n");
	printf("sizeof(int):%ld\n", sizeof(int));
	printf("sizeof(a)  :%ld\n", sizeof(a));
	printf("sizeof a   :%ld\n", sizeof a );
	printf("sizeof float  :%ld\n", sizeof(float));
	printf("sizeof double :%ld\n", sizeof(double));
	printf("sizeof short  :%ld\n", sizeof(short));
	printf("sizeof long  :%ld\n", sizeof(long));
	printf("sizeof char  :%ld\n", sizeof(char));

	return 0;
}
