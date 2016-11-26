/*************************************************************************
    > File Name: src/user.c
    > Author: xiaofan
    > Mail: jianghu_xiaofan@foxmail.com 
    > Created Time: 2016Äê11ÔÂ22ÈÕ ÐÇÆÚ¶þ 15Ê±17·Ö14Ãë
 ************************************************************************/
#include "struct.h"
#include "hide.h"
#include "user.h"
#include <stdio.h>
#include "user_link.h"
#include <string.h>
#include <stdlib.h>
#include "buy_link.h"

//用户注销函数

void user_logout(struct User * User_head)
{
	struct User * temp = NULL;
	struct User * bef = NULL;//新建节点的
	char name[30] ="\0";
	char passworld[50] = "\0";
	
	char id_code_in[5]="\0";//验证
	char id_code_auto[5]="\0";
	
	int i = 0;//记录错误次数
	temp = User_head;
	while(i<2)
	{
		printf("please input username\n");
		scanf("%s",name);
		while(getchar() != '\n');
		
		bef = User_node_find_bef(temp,name);
		if(NULL == bef)
		{
			printf("用户不存在\n");
			i++;//return;
			continue;
		}
	
		printf("请输入密码:\n");
		//scanf("%s",passworld);
		//while(getchar() != '\n');
		getPassword(passworld);
		
		//验证码
		ID_code(id_code_auto);
		printf("验证码为 ：%s\t(区分大小写)\n",id_code_auto);
		printf("请输入验证码：\n");
		scanf("%s",id_code_in);//printf("%s",id_code_auto);
		while(getchar() != '\n');
		
		if( (strcmp(passworld,bef->next->pwd)!=0)&&(strcmp(id_code_auto,id_code_in)!=0) )
		{
			printf("密码或验证码不正确\n请重新输入用户名和密码\n");
			i++;
		}
		else
		{
			if(1 == bef->next->flag)
			{
				printf("该帐号已经注销\n");
				getchar();
				return;
			}
			else
			{
				//处理函数	
				bef->next->flag = 1;//注销标志位
				printf("注销成功\n");
				getchar();
				return;
			}
		}
	}
}





//用户注册
void user_regist(struct User * User_head)
{	
	struct User * temp = NULL;
	char name[30] ="\0";
	char passworld_a[50] = "\0";
	char passworld_b[50] = "\0";
	
	char id_code_in[5]="\0";//验证
	char id_code_auto[5]="\0";
	
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}
	temp = User_head;
	while(1)
	{
		printf("please input username\n");
		scanf("%s",name);
		while(getchar() != '\n');
	
		if(NULL != User_node_find_bef(temp,name))
		{
			printf("用户已经存在!\n");
			printf("退出或重新注册？q or 其他\n");
			if(getchar() == 'q')
			{
				getchar();//清缓存 
				return;
			}
			else
				continue;
		}
		//开始注册
		printf("请输入密码:\n");
		getPassword(passworld_a);
		printf("请再次输入密码:\n");
		getPassword(passworld_b);
		
		//验证码
		ID_code(id_code_auto);
		printf("验证码为 ：%s\t(区分大小写)\n",id_code_auto);
		printf("请输入验证码：\n");
		scanf("%s",id_code_in);//printf("%s",id_code_auto);
		while(getchar() != '\n');
		
		if( (strcmp(passworld_a,passworld_b) == 0)&&(strcmp(id_code_auto,id_code_in)==0) )
		{	
			User_node_add(temp,name,passworld_a);
			printf("注册成功！\n");
			printf("任意键转到上一层\n");
			getchar();
			return;
		}
		else
		{
			printf("两次密码不相符或验证码不正确,请重新输入\n");
		} 
		
	}	
}

//用户登陆验证
void user_login(struct User * User_head)
{
	struct User * temp = NULL;
	struct User * bef = NULL;//新建节点的
	char name[30] ="\0";
	char passworld[50] = "\0";
	int i = 0;//记录错误次数
	
	char id_code_in[5]="\0";//验证
	char id_code_auto[5]="\0";
	if(NULL == User_head)
	{
		printf("in is null1\n");
		return;
	}
	
	temp = User_head;
	while(i<3)
	{
		printf("please input username\n");
		scanf("%s",name);
		while(getchar() != '\n');
		
		bef = User_node_find_bef(temp,name);
		if(NULL == bef)
		{
			printf("用户不存在\n");
			i++;
			continue;
		}
	
		printf("请输入密码:\n");
		getPassword(passworld);
		
		//验证码
		ID_code(id_code_auto);
		printf("验证码为 ：%s\t(区分大小写)\n",id_code_auto);
		printf("请输入验证码：\n");
		scanf("%s",id_code_in);//printf("%s",id_code_auto);
		while(getchar() != '\n');
		
		if( (strcmp(passworld,bef->next->pwd)==0)&&(strcmp(id_code_auto,id_code_in)==0) )
		{
			if(1 == bef->next->flag)
			{
				printf("该帐号注销，请于管理员联系\n");
				getchar();
				return;
			}
			printf("登陆成功\n");
			user_mess_view(bef->next);//处理函数
			return;
		}
		else
		{
			printf("密码或验证码不正确\n请重新输入用户名和密码\n");
			i++;
		}
	}
}


void user_mess_view(struct User * User_message_node)
{
	char choose = 0;
	struct Buy_ticket * Buy_head = NULL;
	Buy_head = malloc(sizeof(struct Buy_ticket));
	Buy_head->next = NULL;
	Buy_file_read(Buy_head);
	
	while(1)
	{	
		system("clear");
		printf("*********管理员菜单*********\n");
		printf("**\t1.查看信息\n");//还有 下注 查记录
		printf("**\t2.修改密码\n");
		printf("**\t3.充值\n");
		printf("**\t4.下注\n");
		printf("**\t5.查记录\n");
		printf("**\t0.exit\n");
		printf("****************************\n");
		printf("请选择: ");
		choose = getchar();
		while(getchar() != '\n');
		switch(choose)
		{
	
			case '1':
					//printf("查看信息\n");
					User_one_node_show(User_message_node);
					getchar();
					break;
			case '2':
					//printf("修改密码\n");
					User_revised_pwd_node(User_message_node);
					Buy_file_write(Buy_head);
					break;
			case '3':
					//printf("充值\n");
					User_addpay_node(User_message_node);
					Buy_file_write(Buy_head);
					break;
			case '4':
					//printf("下注\n");
					Buy_add_node(Buy_head,User_message_node);
					Buy_file_write(Buy_head);//写入
					break;
			case '5':
					//printf("查记录\n");
					Buy_find_history(Buy_head,User_message_node);
					getchar();
					//找购买链表的 与if姓名符合的打印 
					break;
			case '0':
					//printf("exit\n");
					Buy_file_write(Buy_head);//写入
					Buy_node_free(Buy_head);
					free(Buy_head);
					Buy_head = NULL;
					return;
					break;
			default: ;
		}
	}
}






