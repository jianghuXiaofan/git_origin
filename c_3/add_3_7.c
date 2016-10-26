#include <stdio.h>
#include <math.h>
/*
** 注意加入了 math.h 编译时加参数 "-lm" 链接这个库
*/
int main(int argc, char **argv)
{
	double a, b, c;
	double s;
	double  area = 0.0;

	printf("please input a b c\n");
	scanf("%lf %lf %lf",&a, &b, &c);
	if((a > 0) && (b > 0) && (c > 0))
	{
		if((a + b >= c) || (a + c >= b) || (b + c >= a))
		{
			printf("yes\n");
			s = (a + b + c) / 2;
			area = sqrt(s * (s - a) * (s - b) *(s - c));
			printf("Area = %lf\n", area);
		}else printf("NO\n");
	}else printf("NO\n");

}
