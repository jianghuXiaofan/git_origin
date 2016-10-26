#include<stdio.h>
/*
** get circular area & girth  
*/
#define Pi 3.14
int main(int argc, char **argv)
{
	int r;
	float c = 0.0, s = 0.0;
	printf("请输入圆的半径：");
	scanf("%d",&r);
	c = 2*Pi*r;
	s = Pi*r*r;
	printf("半径为：%d 的圆 面积为：%.2f 周长为: %.2f\n", r, s, c);

	return 0;
}
