#include "struct.h"
#include "admin.h"
#include "login_view.h"
#include <stdlib.h>
#include <stdio.h>
#include "user.h"
#include "user_link.h"
#include "ticket_link.h"
#include <string.h>

//管理员选择界面
void admin_select_control(void)
{
	char choose = 0;
	struct User * Admin_head = malloc(sizeof(struct User));
	Admin_head->next = NULL;
	User_file_read(Admin_head);
	User_all_node_show(Admin_head);
	while(1)
	{
		admin_login_view();
		choose = getchar();	
		while(getchar() != '\n');
		switch(choose)
		{
	
			case '1':
					//printf("查看彩民信息\n");//姓名 余额 中奖情况没加
					Admin_find_uesr_control(Admin_head);
					break;
			case '2':
					//printf("发行下一批彩票\n");//设置发行数 单价等
					Admin_Publish_ticket();//这个里面引用链表
					getchar();		
					break;
			case '3':
					//printf("为彩民充值\n");//查余额 充值
					Admin_addpay(Admin_head);	
					User_file_write(Admin_head);	
					break;
			case '4':
					//printf("排序\n");
					Admin_sort_uesr_control(Admin_head);
					User_file_write(Admin_head);		
					break;
			case '5':
					//printf("解冻\n");
					Admin_release_user(Admin_head);
					User_file_write(Admin_head);		
					break;
			case '0':
					User_file_write(Admin_head);
					User_node_free(Admin_head);
					free(Admin_head);
					Admin_head = NULL;
					//printf("exit\n");
					return;
					break;
			default: ;
		}
	}
}


//管理员 排序界面
void Admin_sort_uesr_control(struct User * User_head)
{
	char choose = 0;
	while(1)
	{	
		system("clear");
		printf("**********排序菜单**********\n");
		printf("**\t1.用户名排序\n");
		printf("**\t2.余额排序\n");
		printf("**\t0.exit\n");
		printf("****************************\n");
		printf("请选择: ");
		
		choose = getchar();	
		while(getchar() != '\n');
		switch(choose)
		{
	
			case '1':
					//printf("用户名排序\n");
					Admin_sort_name_show(User_head);
					getchar();
					break;
			case '2':
					//printf("余额排序\n");//
					Admin_sort_money_show(User_head);	
					getchar();	
					break;
			case '0':
					return;					
					break;
			default: ;
		}
	}
}

//管理员通过用户名 排序
void Admin_sort_name_show(struct User * User_head)
{
	struct User * temp = NULL;//当前 
	struct User * bef = NULL;
	int i = 0;
	int j = 0;
	int num = 0;//节点数目
	char flag = 0;//int 占的太大了
	
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}
	
	bef = User_head;
	while(NULL != bef->next)
	{
		num++;
		bef = bef->next;
	}//得到一共多少个节点(不包括头)
	
	for(i = 0;i < num-1;i++)
	{
		bef = User_head;
		temp = bef->next;//每次都回到头
		flag = 1;
		for(j = 0;j < num-i-1;j++)
		{
			if(strcmp(temp->name,temp->next->name) > 0)
			{
				bef->next = temp->next;
				temp->next = bef->next->next;
				bef->next->next = temp;
				flag = 0;
			}
			bef = bef->next;//移项
			temp = bef->next;
		}
		
		if(1 == flag)//
		{
			break;
		}
	}
	printf("排序成功\n");
	getchar();
}

//管理员 根据用户余额 排序
void Admin_sort_money_show(struct User * User_head)
{
	struct User * temp = NULL;//当前 
	struct User * bef = NULL;
	int i = 0;
	int j = 0;
	int num = 0;//节点数目
	char flag = 0;//int 占的太大了
	
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}
	
	bef = User_head;
	while(NULL != bef->next)
	{
		num++;
		bef = bef->next;
	}//得到一共多少个节点(不包括头)
	
	for(i = 0;i < num-1;i++)
	{
		bef = User_head;
		temp = bef->next;//每次都回到头
		flag = 1;
		for(j = 0;j < num-i-1;j++)
		{
			if( (temp->money) > (temp->next->money) )
			{
				bef->next = temp->next;
				temp->next = bef->next->next;
				bef->next->next = temp;
				flag = 0;
			}
			bef = bef->next;//移项
			temp = bef->next;
				
		}
		if(1 == flag)//
		{
			break;
		}
	}
	printf("排序成功\n");
	getchar();
}


//管理员发行彩票
void Admin_Publish_ticket(void)
{
	struct Publish_ticket * Pub_head = malloc(sizeof(struct Publish_ticket));
	Pub_head->next = NULL;
	
	Ticket_file_read(Pub_head);
	Ticket_add_node(Pub_head);
	Ticket_file_write(Pub_head);
	//Ticket_all_node_show(Pub_head);//debug——show!
	Ticket_node_free(Pub_head);
	free(Pub_head);
	Pub_head = NULL;
}


//查看彩民信息

void Admin_find_uesr_control(struct User * User_head)
{
	char choose = 0;
	while(1)
	{	
		system("clear");
		printf("*********管理员菜单*********\n");
		printf("**\t1.姓名查找\n");
		printf("**\t2.余额区间查找\n");
		printf("**\t3.全部查看\n");
		printf("**\t0.exit\n");
		printf("****************************\n");
		printf("请选择: ");
		choose = getchar();	
		while(getchar() != '\n');
		switch(choose)
		{
	
			case '1':
					//printf("姓名查找\n");//姓名 余额 中奖情况
					Admin_find_name_show(User_head);
					getchar();
					break;
			case '2':
					//printf("区间查找\n");//
					Admin_find_inter_show(User_head);		
					break;
			case '3':
					//printf("全部查看\n");//
					User_all_node_show(User_head);
					getchar();		
					break;
			case '0':
					//system("clear");
					return;					
					break;
			default: ;
		}
	}
}

//区间查找

void Admin_find_inter_show(struct User * User_head)
{
	struct User * temp = NULL;//
	int star = 0;
	int end = 0;
	char flag = 0;//记录是不是有
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}
	while(1)
	{
		printf("请输入区间\n");
		scanf("%d %d",&star,&end);
		while(getchar() != '\n');
		if((star>=0)&&(end>=0) !=1)
		{
			printf("请输入正确的数!");
			getchar();
			continue;	
		}
		temp = User_head->next;
		while(temp != NULL)
		{
			if((temp->money >= star)&&(temp->money <= end))
			{
				printf("姓名%s\t密码%s\t金额%.2f\t账户状态%d\n",
					temp->name,temp->pwd,temp->money,temp->flag);
					flag = 1;
			}
			temp = temp->next;
		}
		if(!flag) 
		{
			printf("没找到信息\n");
		}
		printf("q键退出其他继续\n");
		if(getchar() =='q')
		{
			getchar();
			return;
		}
	}
}


//用户名查找显示结果
void Admin_find_name_show(struct User * User_head)
{
	struct User * temp = NULL;
	struct User * bef = NULL;//新建节点的
	char name[30] ="\0";
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
		
		bef = User_node_find_bef(temp,name);
		if(NULL == bef)
		{
			printf("用户不存在\n");
			getchar();
			return;
		}
		User_one_node_show(bef->next);
		return;
	}
}


//管理员为彩民充值
void Admin_addpay(struct User * User_head)
{
	struct User * temp = NULL;
	struct User * bef = NULL;//新建节点的
	char name[30] ="\0";
	float money = 0;
	int i = 0;//记录错误次数
	char flag = 1;//解决冲钱为字母
	if(NULL == User_head)
	{
		printf("in is null\n");
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
			getchar();
			i++;
			continue;
		}

		printf("请输入钱数！\n");
		flag = scanf("%f",&money);
		if(getchar() != '\n') 
		{
			flag = 0;
		}
		while(getchar() != '\n');
		if(flag == 0)
		{
			printf("请输入正确的数字\n");
			getchar();
			flag = 1;
			i++;
		}
		else if(money < 0)
		{
			printf("请输入正确的数字\n");
			getchar();
			i++;
		}
		else 
		{
			i =	0;
			bef->next->money += money; 
			printf("充值成功 当前余额为%.2f\n",
				bef->next->money);
			getchar();
			return;
		}
	}
	printf("输入有误超过3次\n");
	getchar();
}


//管理员为彩民解冻
void Admin_release_user(struct User * User_head)
{
	struct User * temp = NULL;
	struct User * bef = NULL;//新建节点的
	char name[30] ="\0";

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
		
		bef = User_node_find_bef(temp,name);
		if(NULL == bef)
		{
			printf("用户不存在\n");
			getchar();//清缓存
			continue;
		}
		if(bef->next->flag != 1)
		{
			printf("帐号未注销\n");
			getchar();//清缓存
			return;
		}
		bef->next->flag = 0;
		printf("解冻成功\n");
		printf("q退出 其他继续");
		if(getchar()== 'q')
		{
			getchar();//清缓存
			return;
		}
	}
}


