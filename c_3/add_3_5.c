#include<stdio.h>

int main(int argc, char **argv)
{
	int bottom = 0;
	int high = 0;
	float Squr = 0;

	printf("please input bottom & high\n");

	scanf("%d %d",&bottom, &high);
	Squr = (bottom * high) / 2;

	printf("Squa = %.2f\n", Squr);
	return 0;

}
