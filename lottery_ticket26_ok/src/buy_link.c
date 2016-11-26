#include "struct.h"
#include "buy_link.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user_link.h"
#include "ticket_link.h"

//用户下注函数

void Buy_add_node(struct Buy_ticket * Buy_head,struct User * User_message_node)
{
	struct Buy_ticket * temp = NULL;//记录买链表的最后一个
	struct Buy_ticket * p = NULL;//新建的买链表指针
	int num = 0;//根据余额 发行量计算建议购买数量。
	if(NULL == Buy_head)
	{
		printf("in is null\n");
		return;
	}
	if(NULL == User_message_node)
	{
		return;
	}
	
	struct Publish_ticket * publish_end = NULL;//发行链表最后一个
	struct Publish_ticket * Pub_head = malloc(sizeof(struct Publish_ticket));
	Pub_head->next = NULL;//创建发行链表的头
	
	if(Ticket_file_read(Pub_head) != 0)//加载发行链表到内存
	{
		printf("没有发行数据\n");
		//Ticket_node_free(Pub_head);
		free(Pub_head);
		Pub_head = NULL;
		getchar();
		return;
	}
	//Ticket_all_node_show(Pub_head);//发行链表显示
		
	publish_end = Pub_head;
	while(NULL != publish_end->next)
	{
		publish_end = publish_end->next;
	}
	//publish_end->cellCount 发行数量
	//publish_end->issue 最新期号
	//publish_end->state 最新状态
	//publish_end->price//本期单价
	//publish_end->totalMoney//总奖金
	//找到最新的发行期号和状态

	if(publish_end->state != 0)//判断是否开过奖
	{
		printf("本期已经开过奖，请等待下期\n");
		Ticket_node_free(Pub_head);
		free(Pub_head);
		Pub_head = NULL;
		getchar();
		return;
	}
	
	temp = Buy_head;//买链表最后
	while(NULL != temp->next)
	{
		temp = temp->next;		
	}
	if(User_message_node->money < publish_end->price)
	{
		printf("余额不足以购买一注,请充值\n");
		getchar();
		
		Ticket_node_free(Pub_head);
		free(Pub_head);
		Pub_head = NULL;
		return;
	}
	num = (int)(User_message_node->money/publish_end->price);
	num = num>5 ? 5:num;
	//当然不够了。。。
	p = malloc(sizeof(struct Buy_ticket));//新链表
	memset(p,0,sizeof(struct Buy_ticket));
	printf("请输入号码（三个数）\n");
	scanf("%d %d %d",&p->buyNum[0],&p->buyNum[1],&p->buyNum[2]);
	printf("请输入注数,最多5注,根据您的余额最多可买%d注\n",num);
	scanf("%d",&p->zhushu);
	while(getchar()!='\n');
	
	if(publish_end->sellCount > 5) 
	{
		if(p->zhushu > 5) 
		{
			p->zhushu = 5;//强改
		}
	}
	else
	{
		printf("仅剩下%d注\n",publish_end->sellCount);
		p->zhushu = publish_end->sellCount;
		getchar();
	}
	
	if( (User_message_node->money) < (p->zhushu * publish_end->price) )
	{
		printf("余额不足,请充值\n");
		getchar();
		free(p);
		p = NULL;
		Ticket_node_free(Pub_head);
		free(Pub_head);
		Pub_head = NULL;
		return;
	}
	User_message_node->money -= (p->zhushu * publish_end->price);//更新用户余额
	publish_end->totalMoney = publish_end->totalMoney + (p->zhushu * publish_end->price);//更新奖池
	p->issue = publish_end->issue;//复制期号
	strcpy(p->owner,User_message_node->name);//复制购买者
	publish_end->sellCount = publish_end->sellCount - p->zhushu;//发行量减少
	p->ID = temp->ID + 1;//
	p->statue = 0;//0 为没兑奖
	p->next = NULL;
	temp->next = p;
	
	Ticket_file_write(Pub_head);
	Ticket_node_free(Pub_head);
	free(Pub_head);
	Pub_head = NULL;
	printf("下注成功，任意键返回\n");
	getchar();
}

//购买历史察看
void Buy_find_history(struct Buy_ticket * Buy_head,struct User * User_message_node)
{
	struct Buy_ticket * temp = NULL;
	temp = Buy_head->next;
	while(NULL != temp)
	{	
		
		if(strcmp(temp->owner,User_message_node->name) == 0)
		{
			printf("---------------------------------------\n");
			printf("期号\tID\t号码\t注数\t姓名\t状态\t价值\n");
			printf("%d\t%d\t%d %d %d\t %d\t%s\t%d\t%.2f\n",
				temp->issue,temp->ID, temp->buyNum[0],
				temp->buyNum[1],temp->buyNum[2],
				temp->zhushu,temp->owner,temp->statue, temp->money);
		}
		temp = temp->next;
	}
}



//*写
void Buy_file_write(struct Buy_ticket * Buy_head)
{
	struct Buy_ticket * temp = NULL;
	FILE * fp = NULL;
	if(NULL == Buy_head)
	{
		printf("in is null\n");
		return;
	}
	
	fp = fopen("./data/buy_data","wb");
	if(NULL == fp)
	{
		printf("open file fail!ti wb\n");
		return;
	}
	
	temp = Buy_head->next;
	while(NULL != temp)
	{
		fwrite(temp,sizeof(struct Buy_ticket),1,fp);
		temp = temp->next;	
	}
	fclose(fp);
	fp = NULL;
}
//*读
void Buy_file_read(struct Buy_ticket * Buy_head)
{
	
	struct Buy_ticket * temp = NULL;//end
	struct Buy_ticket * p = NULL;
	FILE * fp = NULL;
	if(NULL == Buy_head)
	{
		printf("in is null\n");
		return;
	}

	fp = fopen("./data/buy_data","rb");
	if(NULL == fp) 
	{
		printf("open fail!ti rb\n");
		return;
	}
	temp = Buy_head;
	while(NULL != temp->next)
	{
		temp = temp->next;	
	}//find end  node
	
	while(1)
	{		
		p = malloc(sizeof(struct Buy_ticket));
		
		fread(p,sizeof(struct Buy_ticket),1,fp);
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


//*释放
void Buy_node_free(struct Buy_ticket * Buy_head)
{
	struct Buy_ticket * after = NULL;
	struct Buy_ticket * temp = NULL;
	if(NULL == Buy_head)
	{
		printf("in is null\n");
		return;
	}
	temp = Buy_head->next;
	while(NULL != temp)
	{
		after = temp->next;
		free(temp);
		temp =after;
	}
}

