#include <stdio.h>

int main(int argc, char **argv)
{
	char a;
	char b;

	scanf("%c",&a);
	
	printf("%c\n", a);
	if((a >= 65) && (a <= 65 + 26))
	{
		b = a + 32;
		printf("大-->%c\n", b);
	}
	if((a >= 97) && (a <= 97 + 26))
	{
		b = a - 32;
		printf("小 -->%c\n", b);
	}
	
	return 0;
}
