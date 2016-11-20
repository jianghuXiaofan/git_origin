#include "fun_login.h"
#include <string.h>
#include <stdio.h>
#include "control.h"

void login(void)
{
	char username[30] = "\0";
	char password[20] = "\0";
	int i = 0;//记录错误登陆 超过3次推出
	int flag = 0;
	do 
	{
		/***************************debug for teacher******************************/
		printf("username: admin\npassword: 123\n");
		/***************************debug for student******************************/
		printf("username: stu\npassword: 123\nfor debug!_xiaofan\n");
			
		printf("please input user name:");
		
		scanf("%s",username);
		while(getchar() != '\n');
		printf("please input password:");
		printf("\033[8m");//消隐背景色
		scanf("%s",password);
		printf("\033[m");//恢复 //这样隐藏密码会不会被打！！！
		printf("密码并不显示！！\n");
		
		while(getchar() != '\n');
	
		if( (strcmp(username,"admin")==0) && 
			(strcmp(password,"123")==0) )
		{
			//printf("login successfull!\n");
			i  = 0;//成功登录1次 就该清零计数
		
			fun_teach_view();
			
			printf("退出 or 重新登录 ?y or c\n");
			switch (getchar())
			{
			 	case 'y' : flag = 0; //设个标志位选择下直接退到上一目录 还是换个人登录
			 			return;
			 			break;
			 	case 'c' : flag = 1; 
			 			break;
			 	default : printf("in is error\n");
			}
			
		}else if((strcmp(username,"stu")==0) && 
			    (strcmp(password,"123")==0) )//这里写死了，实际这样并不好，不等一直ifelse 万一 2万多人的，要改进^__^
		{
			printf("student login successfull\n");
			i  = 0;//成功登录1次 就该清零计数
			
			fun_student_view();
			
			printf("退出 or 重新登录 ?y or c\n");//既然一样 应该另开函数 ！！改！
			switch (getchar())
			{
			 	case 'y' : flag = 0; 
			 			return;
			 			break;
			 	case 'c' : flag = 1; 
			 			break;
			 	default : printf("in is error\n");
			}
			
		}
		else 
		{
			i++;
			if(i >= 3)
			{
				flag = 0;
			}
		}
	}while(flag);
}
