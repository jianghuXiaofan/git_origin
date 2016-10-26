#include <stdio.h>
void printf_bit(int n);

int main(int argc, char **argv)
{
	int a, b;
	printf("请输入一个整数：");
	scanf("%d",&a);
	printf("\n%d的倒数三位为:为",a);
  	b = a & 4;
	if(b == 4)
  	printf("1\n");
	else printf("0\n");
	printf("%d的2进制数为\n", a);
    
	printf_bit(a);

	return 0;
}

void printf_bit(int n)
{
	long l = sizeof(n) * 8;	
	long i = 0;

	if(i == 0) printf("0");//二进制首位最好为0,好分辨 并不是默认个人习惯
	
	for (i = l - 1; i >= 0; i--)
	{
		if(n & (1 << i)) break;
	}

	for ( ; i >= 0; i--) printf("%d",(n & (1 << i)) != 0);
	printf("\n");
	
}
