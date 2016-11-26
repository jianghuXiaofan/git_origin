/*************************************************************************
    > File Name: control.c
    > Author: xiaofan
    > Mail: jianghu_xiaofan@foxmail.com 
    > Created Time: 2016Äê11ÔÂ22ÈÕ ÐÇÆÚ¶þ 10Ê±04·Ö08Ãë
 ************************************************************************/
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "hide.h"
#include "control.h"
#include "login_view.h"
#include "user.h"
#include <string.h>
#include "user_link.h"
#include "admin.h"
#include "gref.h"
#include<time.h>

//主控制台
void  login_control(void)//第1层
{
	char choose = 0;
	while(1)
	{
		login_view();//彩票系统 管理员 用户 公正	
		choose = getchar();
		while(getchar() != '\n');
		switch (choose)
		{
			case '1':
					//printf("admin\n");
					admin_login_control();
		 			break;
			case '2':
		 			//printf("user\n");
					user_login_control();
					break;
			case '3':
		 			//printf("gref\n");
		 			greffier_login_control();
					break;
			case '0':
		 			 //printf("tuichu\n");
					 return;
					 break;
			default : ;
		}
	}
}

//公正员登陆验证
void greffier_login_control(void)//第2层greffier
{
	int i = 0;//记录错误次数
	char name[20] ="\0";
	char passworld[20] = "\0";
	
	char id_code_in[5]="\0";//验证
	char id_code_auto[5]="\0";
	
	while(i<3)
	{
		printf("请输入帐号：（提示gref 123）\n");
		scanf("%s",name);
		while(getchar() != '\n');
		
		if(strcmp(name,"gref") != 0)
		{
			printf("用户不存在\n");
			i++;
			getchar();
			continue;
		}
		printf("请输入密码：\n");
		getPassword(passworld);
		//验证码
		ID_code(id_code_auto);
		printf("验证码为 ：%s(区分大小写)\n",id_code_auto);
		printf("请输入验证码：\n");
		scanf("%s",id_code_in);//printf("%s",id_code_auto);
		while(getchar() != '\n');
		
		if( (strcmp(passworld,"123")==0)&&(strcmp(id_code_auto,id_code_in)==0) )
		{
			
			i = 0;
			printf("登陆成功\n");
			//处理函数	
			gref_select_control();
			return;
		}
		else
		{	
			printf("密码或验证码不正确\n请重新输入用户名和密码\n");
			i++;
		}	
	}

}

//管理员验证登陆界面
void admin_login_control(void)//第2层admin
{
	int i = 0;//记录错误次数
	char name[30] ="\0";
	char passworld[20] = "\0";
	
	char id_code_in[5]="\0";//定义成这样好验证
	char id_code_auto[5]="\0";
	
	while(i<3)
	{
		printf("请输入帐号：\n");
		scanf("%s",name);
		while(getchar() != '\n');
		if(strcmp(name,"admin") != 0)
		{
			printf("用户不存在\n");
			getchar();
			continue;
		}
		
		printf("请输入密码：\n");
		getPassword(passworld);

		//验证码
		ID_code(id_code_auto);
		printf("验证码为 ：%s(区分大小写)\n",id_code_auto);
		printf("请输入验证码：\n");
		scanf("%s",id_code_in);//printf("%s",id_code_auto);
		while(getchar() != '\n');
		
		if ( (strcmp(passworld,"123")==0)&&(strcmp(id_code_auto,id_code_in)==0) )
		{
			i = 0;
			printf("登陆成功\n");
			system("clear");
			//处理函数	
			admin_select_control();
			return;
		}
		else
		{	
			printf("密码或验证码不正确\n请重新输入用户名和密码\n");
			i++;
		}	
	}
}

//用户登陆验证
void user_login_control(void)//第2层user
{
	char choose = 0;
	struct User * User_head = malloc(sizeof(struct User));
	memset(User_head,0,sizeof(struct User));//初始化
	User_head->next = NULL;
	User_file_read(User_head);
	//User_all_node_show(User_head);
	while(1)
	{
		user_login_view();//用户登陆选择界面

		choose = getchar();
		while(getchar() != '\n');
		switch(choose)
		{
			case '1':
					//printf("注册\n");
					user_regist(User_head);
					User_file_write(User_head);
					User_all_node_show(User_head);
					break;
			case '2':
					user_login(User_head);
					User_file_write(User_head);
					//printf("登录\n");
					break;
			case '3':
					//printf("注销\n");
					user_logout(User_head);
					User_file_write(User_head);
					break;
			case '0':
					//printf("exit\n");
					User_file_write(User_head);
					User_node_free(User_head);
					free(User_head);
					User_head = NULL;
					return;
					break;
			default : ;
		}
	}
}


