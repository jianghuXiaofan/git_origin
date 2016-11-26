#include "hide.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

//#include<stdlib.h>
//#include<time.h>
//srand(time(NULL));//产生随机数
//int k = rand()%10;
/*
for(i = 0 ; i<5;i++)
{
	while(j<1000000)// 动态效果
{
	k= rand()%10;
	printf("\r%d",k);
	j++;
}
j = 0;	
}
//printf("%d\n",k);//
*/

//产生验证码
void ID_code(char id_code_auto[])
{	
	srand(time(NULL));
	int j=0;
	int k=0;
	for(j=0;j<4;j++)
	{
		while(k<3000)
		{
			k++;
			*(id_code_auto+j) = rand()%62;//26+26+10
		}
		k = 0;
		if(*(id_code_auto+j)<10) 
		{
			id_code_auto[j] = id_code_auto[j] + '0';
		}
		else if(*(id_code_auto+j)<36)  
		{
			id_code_auto[j] = id_code_auto[j] -10 + 'a';
		}
		else 
		{
			id_code_auto[j] = id_code_auto[j] - 36 + 'A';
		}
	}
		//id_code_auto[4] = '\0';//也许不用
}
		


//getPassword(temp);
/*****************************************
 * 功能：设置终端为不回显不缓冲，并获取按键的键值
 * 返回值：按键的键值int型
 * 参数：无参数
 ****************************************/
int getch(void)
{
        struct termios tm, tm_old;
        int fd = STDIN_FILENO, c;
        if(tcgetattr(fd, &tm) < 0)	//获取终端属性
        {
            return -1;
        }
        tm_old = tm;
        cfmakeraw(&tm);	//就是将终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理。
        				//在原始模式下，终端是不可回显的，而且所有特定的终端输入/输出模式不可用。
        if(tcsetattr(fd, TCSANOW, &tm) < 0)	//不等数据传输完毕就立即改变属性   成功返回0   失败-1
        {
            return -1;
        }
        c = fgetc(stdin);//
        if(tcsetattr(fd, TCSANOW, &tm_old) < 0)
        {
            return -1;
        }
        return c;
}

/*****************************************
 * 功能：调用getch获取键值保存到pcPWD中并单个回显*
 * 		可以分别backspace和回车
 * 		用于获取密码
 * 返回值:无返回值
 * 参数：字符数组指针pcPWD
 ****************************************/

void getPassword(char *pcPWD)
{
	int ch=0;
	int i=0;
	for(i=0;i<20;)
	{
		ch=getch();
		if(ch==-1)
		{
			continue;
		}
		if((ch == 127 || ch == 8) && i>0)
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
			i--;
		}
		else if(ch==10 || ch == 13)
		{
			pcPWD[i]=0;
			putchar('\n');
			return;
		}
		else if(i==0&&(ch==127 ||ch == 8))
		{
			printf("\a");
		}
		else if(i<19)
		{
			pcPWD[i]=(char)ch;
			putchar('*');
			i++;
		}
		else
		{
			printf("\a");
		}
	}
}

