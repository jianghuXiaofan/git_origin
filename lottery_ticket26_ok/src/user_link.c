/*************************************************************************
    > File Name: src/link.c
    > Author: xiaofan
    > Mail: jianghu_xiaofan@foxmail.com 
    > Created Time: 2016Äê11ÔÂ22ÈÕ ÐÇÆÚ¶þ 13Ê±37·Ö20Ãë
 ************************************************************************/
#include "struct.h"
#include "user_link.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hide.h"
//*增
void User_node_add(struct User * User_head,char *name,char * pwd)
{
	struct User * temp = NULL;
	struct User * p = NULL;
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}
	temp = User_head;
	while(NULL != temp->next)
	{
		temp = temp->next;
	}
	p = malloc(sizeof(struct User));
	memset(p,0,sizeof(struct User));
	//printf("请输入信息\n");
	strcpy(p->name,name);
	strcpy(p->pwd,pwd);
	p->money = 0;
	p->next = NULL;
	temp->next = p;
}
//*删
void User_del_node_by_name(struct User * User_head,char * name)
{
	struct User * bef = NULL;//前面一个
	struct User * temp = NULL;//当前
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}
	bef = User_node_find_bef(User_head,name);
	if(NULL == bef)
	{
		printf("no message\n");
		return;
	}
	temp = bef->next;
	bef->next = temp->next;
	free(temp);
	temp = NULL;
	printf("成功删除!\n");
}
//*改 密码
void User_revised_pwd_node(struct User * User_message_node)
{
	char passworld[50] = "\0";
	char passworld_a [50] = "\0";
	char passworld_b [50] = "\0";
	int i = 0;
	if(NULL == User_message_node)
	{
		printf("in is null\n");
		return;
	}
	while(i<3)
	{
		printf("请输入原来密码:\n");
		//scanf("%s",passworld);
		//while(getchar() != '\n');
		getPassword(passworld);
		if(strcmp(passworld,User_message_node->pwd)!=0)
		{
			printf("密码不相符\n");
			i++;			
			continue;
		}
		printf("请输入新密码:\n");
		//scanf("%s",passworld_a);
		//while(getchar() != '\n');
		getPassword(passworld_a);
		if(strcmp(passworld,passworld_a)==0)
		{
			printf("与旧密码相同，请更换\n");
			continue;
		}
		printf("请再次输入新密码:\n");
		//scanf("%s",passworld_b);
		//while(getchar() != '\n');
		getPassword(passworld_b);
		if(strcmp(passworld_a,passworld_b)!=0)
		{
			printf("两次密码不相符\n");
			i++;
			continue;
		}
		else
		{
			strcpy(User_message_node->pwd,passworld_b);
			printf("改密码成功\n任意键退出\n");
			getchar();//等待
			return;
		}
	}
}
//用户自己充值
void User_addpay_node(struct User * User_message_node)//char flag  可用于硬件机器改变
{
	float money = 0;
	int i = 0;
	char flag = 1;//用于察看输入字母情况
	if(NULL == User_message_node)
	{
		printf("in is null\n");
		return;
	}
	
	while(i<3)
	{
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
			flag = 1;
			i++;
		}
		else if(money < 0)
		{
			printf("请输入正确的数字\n");
			i++;
		}
		else 
		{
			i =	0;
			User_message_node->money += money; 
			printf("充值成功 当前余额为%.2f\n",
				User_message_node->money);
			getchar();//等待下
			return;
		}
	}
	printf("输入有误超过3次\n");
	getchar();
}

//*查
struct User * User_node_find_bef(struct User * User_head,char * name)
{
	struct User * bef = NULL;
	if(NULL == User_head)
	{
		printf("in is null\n");
		return NULL;
	}
	
	bef = User_head;
	while(NULL != bef->next)
	{
		if(strcmp(name,bef->next->name) == 0)
		{
			return bef;
		}
		bef = bef->next;
	}
	return NULL;
}

//排//放管理员那里了

//*显示所有的用户信息
void User_all_node_show(struct User * User_head)
{
	struct User * temp = NULL;
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}
	temp = User_head->next;
	while(NULL != temp)
	{
		printf("姓名%s\t密码%s\t金额%.2f\t账户状态%d\n",
		temp->name,temp->pwd,temp->money,temp->flag
		);
		temp = temp->next;
	}
}
//察看单个用户信息
void User_one_node_show(struct User * User_message_node)
{
	if(NULL == User_message_node)
	{
		printf("in is null\n");
		return;
	}
	printf("姓名%s\t密码%s\t金额%.2f\t账户状态%d\n",
		User_message_node->name,
		User_message_node->pwd,
		User_message_node->money,
		User_message_node->flag
		);
}
//*释放
void User_node_free(struct User * User_head)
{
	struct User * after = NULL;
	struct User * temp = NULL;
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}
	temp = User_head->next;
	while(NULL != temp)
	{
		after = temp->next;
		free(temp);
		temp =after;
	}
}
//*写
void User_file_write(struct User * User_head)
{
	struct User * temp = NULL;
	FILE * fp = NULL;
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}
	
	fp = fopen("./data/data","wb");
	if(NULL == fp)
	{
		printf("open file fail!wb\n");
		return;
	}
	
	temp = User_head->next;
	while(NULL != temp)
	{
		fwrite(temp,sizeof(struct User),1,fp);
		temp = temp->next;	
	}
	fclose(fp);
	fp = NULL;
}

//*读
void User_file_read(struct User * User_head)
{
	
	struct User * temp = NULL;//end
	struct User * p = NULL;
	FILE * fp = NULL;
	if(NULL == User_head)
	{
		printf("in is null\n");
		return;
	}

	fp = fopen("./data/data","rb");
	if(NULL == fp) 
	{
		printf("open fail!rb\n");
		return;
	}
	rewind(fp);
	temp = User_head;
	while(NULL != temp->next)
	{
		temp = temp->next;	
	}//find end  node
	
	while(1)
	{		
		p = malloc(sizeof(struct User));
		
		fread(p,sizeof(struct User),1,fp);
		if(feof(fp)) //注意到尾部返回1
		{
			free(p);
			p = NULL;
			break;
		}
		p->next = NULL;
		temp->next = p;
		temp = p;
	}
	
	fclose(fp);
	fp = NULL;
}















