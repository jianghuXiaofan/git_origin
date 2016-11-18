#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "file_wr_rd.h"

void file_read(struct stu_node * head)
{
	FILE * fp = NULL;
	struct stu_node * temp = NULL;//end
	struct stu_node * p = NULL;
	
	fp = fopen("./data/test.txt","rb");
	if(NULL == fp) 
	{
		printf("open error rb\n");
		return;
	}
	if(NULL == head)
	{
		printf("in is null\n");
		return;
	}
	rewind(fp);
	temp = head;
	while(NULL != temp->next)
	{
		temp = temp->next;	
	}//find end  node
	
	do
	{
		p = malloc(sizeof(struct stu_node));
		if(NULL == p)
		{
			printf("分配空间失败\n");//学长提示 这样更好些！确实有分配不出空间的情况
			return;
		}
		
		fread(p,sizeof(struct stu_node),1,fp);
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
	while(1);
	
	fclose(fp);
	fp = NULL;
}

void file_write(struct stu_node * head)
{
	FILE * fp = NULL;
	struct stu_node * temp = NULL;
	
	fp = fopen("./data/test.txt","wb");
	if(NULL == fp) 
	{
		printf("open error wr\n");
		return;
	}
	if(NULL == head)
	{
		printf("in is null\n");
		return;
	}
	rewind(fp);
	temp = head->next;
	while(temp != NULL)
	{
		fwrite(temp,sizeof(struct stu_node),1,fp);
		temp = temp->next;
	}
	fclose(fp);
	fp = NULL;
}
