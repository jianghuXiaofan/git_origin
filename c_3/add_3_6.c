#include<stdio.h>
/*
**
*/

#define Pi 3.14
int main(int argc, char **argv)
{
	int r = 0;
	float Squa = 0.0;
	float Vol = 0.0;
	
	printf("please input r = ");
	scanf("%d", &r);
	
	Squa = 4 * Pi * r * r;
	Vol = (4 / 3) * Pi * r * r * r;

	printf("Squar = %.2f\nVol = %.2f\n", Squa, Vol);

	return 0;
}
