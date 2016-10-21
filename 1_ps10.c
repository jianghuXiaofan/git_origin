#include <stdio.h>
#include <math.h>

/* 
** 注意：编译时"gcc *.c -o run -lm " 即编译加 “-lm” 参数表示链接到math.h
*/

int main(int argc , char **argv)
{
	double x = 0.0;
	double s = 0.0;

	printf("input number :\n");
	scanf("%lf",&x);
	s = sin(x);
	printf("sine of %lf is %lf\n",x,s);

	return 0;
}
