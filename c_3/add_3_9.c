#include <stdio.h>
#include <math.h>

//编译时加 -lm 参数

int main(int argc, char **argv)
{
	float a, b, c, disc, x1, x2, p, q;
	printf("please input a b c value\n");
	printf("依次输入a b c 的值请确保b^2-4ac>0\n");
	scanf("%f %f %f", &a, &b, &c);

	disc = b * b - 4 * a * c;
	p = -b / (2 * a);
	q = sqrt(disc) / (a * 2);

	x1 = p + q;
	x2 = p - q;

	printf("\nx1 = %5.2f\nx2 = %5.2f\n", x1, x2);

	return 0;
}
