#include<stdio.h>
/*
** input length & width output square
*/
int main(int argc, char **argv)
{
	int length = 0;
	int width = 0;
	int Square = 0;

	printf("please input length & width!\n");
	//scanf("%d", &length);
	//	scanf("%d", &width);

	scanf("%d %d",&length, &width);
	Square = length * width;
	
	printf("length = %d width = %d\n", length, width);

	printf("Square = %d\n",Square);

	return 0;
}

