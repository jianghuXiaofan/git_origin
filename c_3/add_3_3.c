#include<stdio.h>
/*
**get globe square&volume
** globe = 4*Pi*r^2
** volume = (4/3)*Pi*r^3 
*/
#define Pi 3.14
int main(int argc, char **argv)
{
	int r = 10;
	float Squa = 0.0;
	float Vol = 0.0;

	Squa = 4 * Pi * r * r;
	Vol = (4 / 3) * Pi * r * r * r;
	printf("Squa = %.4f\nVol =  %.4f\n", Squa, Vol);

	return 0;
	//exit(0);
}
