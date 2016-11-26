#include "struct.h"
#include "ticket_link.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//发行彩票
void Ticket_add_node(struct Publish_ticket * Pub_head)
{
	struct Publish_ticket * temp = NULL;
	struct Publish_ticket * p = NULL;
	char flag = 0;
	if(NULL == Pub_head)
	{
		printf("in is null\n");
		return;
	}
	temp = Pub_head;
	if(temp->next == NULL)//说明链表中没有数据要初始化设置
	{
		flag = 1;//说明是首次因此要设置状态 设置奖池初始资金
	}
	while(NULL != temp->next)
	{
		temp = temp->next;		
	}
	
	p = malloc(sizeof(struct Publish_ticket));
	memset(p,0,sizeof(struct Publish_ticket));
	if(flag == 1) 
	{
		//设置	
		printf("第一次发行\n");
		p->issue = 1;
		p->state = 0;//1以开奖
		printf("请设置奖池金额：\n");
		scanf("%f",&p->totalMoney);
		
		printf("请输入单张金额:\n");
		scanf("%f",&p->price);
		printf("请设置发行数目:\n");
		scanf("%d",&p->sellCount);
		printf("发行成功\n");
		getchar();
		p->next = NULL;
		temp->next = p;	
	}
	else
	{
		if(temp->state == 0)
		{
			printf("上期尚未开奖，发行失败！\n");
			getchar();
			free(p);
			p = NULL;
			return;
		}
		
		printf("请输入单张金额:\n");
		scanf("%f",&p->price);
		printf("请设置发行数目:\n");
		scanf("%d",&p->sellCount);
		printf("发行成功\n");
		getchar();
		
		p->issue = temp->issue + 1; 
		p->state = 0;//测试
		p->totalMoney += temp->totalMoney;
		p->next = NULL;
		temp->next = p;
	}
}


//发行记录察看
void Ticket_all_node_show(struct Publish_ticket * Pub_head)
{
	struct Publish_ticket * temp = NULL;
	if(NULL == Pub_head)
	{
		printf("in is null\n");
		return;
	}
	temp = Pub_head->next;
	while(NULL != temp)
	{
		printf("期数\t单价\t中奖号码\t状态\t未售出\t池总\n");
		printf("%d\t%.2f\t%d  %d  %d\t \t%d\t%d\t%.2f\n",
				temp->issue,temp->price,temp->num[0],
				temp->num[1],temp->num[2],
				temp->state,temp->sellCount,
				temp->totalMoney
				);
		temp = temp->next;
	}	
}
//*写
void Ticket_file_write(struct Publish_ticket * Pub_head)
{
	struct Publish_ticket * temp = NULL;
	FILE * fp = NULL;
	if(NULL == Pub_head)
	{
		printf("in is null\n");
		return;
	}
	
	fp = fopen("./data/ticket_data","wb");
	if(NULL == fp)
	{
		printf("open file fail!ti wb\n");
		return;
	}
	
	temp = Pub_head->next;
	while(NULL != temp)
	{
		fwrite(temp,sizeof(struct Publish_ticket),1,fp);
		temp = temp->next;	
	}
	fclose(fp);
	fp = NULL;
}
//*读
int Ticket_file_read(struct Publish_ticket * Pub_head)
{
	
	struct Publish_ticket * temp = NULL;//end
	struct Publish_ticket * p = NULL;
	FILE * fp = NULL;
	if(NULL == Pub_head)
	{
		printf("in is null\n");
		return -1;
	}

	fp = fopen("./data/ticket_data","rb");
	if(NULL == fp) 
	{
		printf("open fail!ti rb\n");
		return 1;//1 代表没有数据
	}
	
	temp = Pub_head;
	while(NULL != temp->next)
	{
		temp = temp->next;	
	}//find end  node
	
	while(1)
	{		
		p = malloc(sizeof(struct Publish_ticket));
		
		fread(p,sizeof(struct Publish_ticket),1,fp);
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
	return 0;
}

//*释放
void Ticket_node_free(struct Publish_ticket * Pub_head)
{
	struct Publish_ticket * after = NULL;
	struct Publish_ticket * temp = NULL;
	if(NULL == Pub_head)
	{
		printf("in is null\n");
		return;
	}
	temp = Pub_head->next;
	while(NULL != temp)
	{
		after = temp->next;
		free(temp);
		temp =after;
	}
	//printf("成功释放内存！\n");
}


