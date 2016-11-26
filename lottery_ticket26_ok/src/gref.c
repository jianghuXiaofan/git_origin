#include "struct.h"
#include "gref.h"
#include "control.h"
#include "login_view.h"
#include <stdio.h>
#include "ticket_link.h"
#include "user_link.h"
#include "buy_link.h"
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

//#include<stdlib.h>
#include<time.h>
//srand(time(NULL));//产生随机数
//int k = rand()%10;

//公正员功能界面
void gref_select_control(void)
{
	char choose = 0;
	struct Publish_ticket * Pub_head = malloc(sizeof(struct Publish_ticket));
	Pub_head->next = NULL;
	Ticket_file_read(Pub_head);
	//Ticket_all_node_show(Pub_head);//debug
	
	while(1)
	{
		gref_login_view();
		choose = getchar();	
		while(getchar() != '\n');
		switch(choose)
		{
	
			case '1':
					//printf("开奖后自动兑奖\n");
					Gref_open(Pub_head);	
					Gref_exchange(Pub_head);
					//只改最后一次的state，加入号码			
					Ticket_file_write(Pub_head);
					break;
			case '2':
					//printf("查询往期彩票\n");//设置发行数 单价等
					Ticket_all_node_show(Pub_head);//打印彩票发行链表
					getchar();		
					break;
			case '0':
					//printf("exit\n");
					Ticket_file_write(Pub_head);
					Ticket_node_free(Pub_head);
					free(Pub_head);
					Pub_head = NULL;
					return;
					break;
			default: ;
		}
	}
}

//公正员兑奖函数

void Gref_exchange(struct Publish_ticket * Pub_head)
{
	struct Publish_ticket * publish_end = NULL;//发行链表最后一个
	float money = 0;//用来设置中奖金额
	if(NULL == Pub_head)
	{
		printf("in is null\n");
		return;
	}
	if(NULL == Pub_head->next)
	{
		printf("尚未发行\n");
		getchar();
		return;
	}
	publish_end = Pub_head;
	while(NULL != publish_end->next)
	{
		publish_end = publish_end->next;
	}
	//publish_end->issue 最新期号
	//publish_end->state 最新状态
	//publish_end->sellCount//购买人数 
	//publish_end->totalMoney奖池总额num[3]
	//找到最新的发行期号和状态
	if(publish_end->state == 0)//判断是否开过奖
	{
		printf("本期尚未开奖，请等待!\n");
		getchar();
		return;
	}
	money = (publish_end->totalMoney) / (publish_end->sellCount);//奖池总额 / 购买数


//////////////////////////////////////////////////////
	struct User * User_bef = NULL;//找到用户前一个
	struct User * User_head = malloc(sizeof(struct User));
	memset(User_head,0,sizeof(struct User));//初始化
	User_head->next = NULL;
	User_file_read(User_head);
	
	
//////////////////////////////////////////////////////
	struct Buy_ticket * Buy_temp = NULL;
	struct Buy_ticket * Buy_head = NULL;
	Buy_head = malloc(sizeof(struct Buy_ticket));
	memset(Buy_head,0,sizeof(struct Buy_ticket));//初始化
	Buy_head->next = NULL;
	Buy_file_read(Buy_head);
	
	
	Buy_temp = Buy_head->next;
	while(NULL != Buy_temp)
	{	
		if(Buy_temp->issue == publish_end->issue)
		{
			//if(strcmp(Buy_temp->buyNum,publish_end->num)==0)//这样比较有隐患
			if ( (Buy_temp->buyNum[0]==publish_end->num[0])
				&&(Buy_temp->buyNum[1]==publish_end->num[1])
				&&(Buy_temp->buyNum[2]==publish_end->num[2]) )//这样比较。。。无赖中奖太难了
			{
				Buy_temp->money = (money * Buy_temp->zhushu);
				publish_end->totalMoney -= Buy_temp->money;//奖池金额减少
				
				User_bef = User_node_find_bef(User_head,Buy_temp->owner);//找到ownr前一个结点
				User_bef->next->money += Buy_temp->money;
			}
		}
		Buy_temp->statue = 1;//兑奖状态
		Buy_temp = Buy_temp->next;
	}
	
	User_file_write(User_head);
	User_node_free(User_head);
	free(User_head);
	User_head = NULL;
	
	Buy_file_write(Buy_head);//写入
	Buy_node_free(Buy_head);
	free(Buy_head);
	Buy_head = NULL;
	printf("已自动兑奖\n");
	getchar();
}


//公正员开奖
void Gref_open(struct Publish_ticket * Pub_head)//传入发布头节点
{
	struct Publish_ticket * publish_end = NULL;//发行链表最后一个
	int num[3] = {};
	int i = 0;
	int j = 0;
	
	if(NULL == Pub_head)
	{
		printf("in is null\n");
		return;
	}
	if(NULL == Pub_head->next)
	{
		printf("尚未发行\n");
		getchar();
		return;
	}
	publish_end = Pub_head;
	while(NULL != publish_end->next)
	{
		publish_end = publish_end->next;
	}
	
	//publish_end->issue 最新期号
	//publish_end->state 最新状态
	//publish_end->price//本期单价
	//找到最新的发行期号和状态

	if(publish_end->state != 0)//判断是否开过奖
	{
		printf("本期已经开过奖，请等待下期\n");
		getchar();
		return;
	} 
#if 0
	printf("手动请输入号码（三个数）测试\n");
	scanf("%d %d %d",&publish_end->num[0],
		&publish_end->num[1],
		&publish_end->num[2]);
#endif

	srand(time(NULL));//产生随机数
#if 1
	printf("请等待开奖\n");
	for(i = 0;i < 3;i++)
	{
		while(j<200000)
		{
			num[i] = rand()%5;//10
			printf("\r%d",num[i]);
			j++;
		}
		j=0;
		putchar('\n');
	}
	printf("中奖号为:");
	for(i = 0;i<3;i++)
	{
		publish_end->num[i] = num[i];
		printf("%d ",num[i]);
	}
	putchar('\n');
	getchar();
#endif

	publish_end->state = 1;//1 为过开奖
}


