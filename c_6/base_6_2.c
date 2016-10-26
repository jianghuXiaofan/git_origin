#include <stdio.h>

int main(int argc, char **argv)
{
	int a;
	int b,c;
	int d;
	printf("请输入一个2位数:");
	scanf("%d",&a);
	b = a / 10;
	c = a % 10;
	d = c * 10 + b;
	printf("逆序输出 %d ==> %d\n", a, d);
	return 0;
}
