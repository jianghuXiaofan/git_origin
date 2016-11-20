#include "struct.h"
#include "link.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
	增加节点
*/
void insert_student_node(struct stu_node * head)
{
	struct stu_node * temp = NULL;
	struct stu_node * p = NULL;
	if(NULL == head)
	{
		printf("in is null\n");
		return;
	}
	temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	
	p = malloc(sizeof(struct stu_node));
	if(NULL == p)
	{
		printf("分配空间失败\n");//学长提示 这样更好些！确实有分配不出空间的情况
		return;
	}
	printf("请输入学号:");
	scanf("%d",&p->stu.ID);
	printf("请输入姓名:");
	scanf("%s",p->stu.name);
	while(getchar() != '\n');
	
	printf("请依次输入英语、数学、语文成绩:\n");
	scanf("%f%f%f",&p->stu.mark.english,
				   &p->stu.mark.math,
				   &p->stu.mark.chinese
	);
	while(getchar() != '\n');
	
	p->stu.mark.grade_sum = p->stu.mark.chinese
							+p->stu.mark.math
							+p->stu.mark.chinese;
	p->next = NULL;
	temp ->next = p;
}
/*
	查看	
*/
void output_show(struct stu_node * head)
{
	struct stu_node * temp = NULL;
	if(NULL == head)
	{
		printf("in is null\n");
		return;
	}
	temp = head->next;
	while(temp != NULL)
	{
		printf("学号：%d\t姓名：%s\t英语：%f\t数学：%f\t语文：%f\t总分：%f\n",
		temp->stu.ID,
		temp->stu.name,
		temp->stu.mark.english,
		temp->stu.mark.math,
		temp->stu.mark.chinese,
		temp->stu.mark.grade_sum
		);
		temp = temp->next;
	}
}
/*
	查找前一个 （姓名）
*/
struct stu_node * find_name_bef_student_node(struct stu_node * head,char * name)
{
	struct stu_node * temp = NULL;
	if(NULL == head)
	{
		printf("in is null\n");
		return NULL;
	}
	temp = head;
	//strcmp(temp->stu.name,name);
	while(0 != strcmp(temp->next->stu.name,name))
	{
		temp = temp->next;
	}
	return temp;
}
/*
	查找 name并显示
*/
void find_name_now_student_node(struct stu_node * head)
{
	struct stu_node * temp = NULL;
	char name[20] = "";
	if(NULL == head)
	{
		printf("in is null\n");
		return;
	}
	printf("请输入要查找的姓名：");
	scanf("%s",name);
	while(getchar() != '\n');
	temp = find_name_bef_student_node(head,name);
	if(NULL == temp)
	{
		printf("no find data!!\n");
		return;
	}//注意这里的处理 昨晚根本没注意到！！重大失误！！！
	temp = temp->next;
	printf("学号：%d\t姓名：%s\t英语：%f\t数学：%f\t语文：%f\t总分：%f\n",
		temp->stu.ID,
		temp->stu.name,
		temp->stu.mark.english,
		temp->stu.mark.math,
		temp->stu.mark.chinese,
		temp->stu.mark.grade_sum
		);	
}
/*
	修改 由name 然后改其他的
*/
void xiugai_name_student_node(struct stu_node * head)
{
	struct stu_node * p = NULL;
	char name[20] = "";
	if(NULL == head)
	{
		printf("in is null\n");
		return;
	}
	printf("请输入要修改的姓名：");
	scanf("%s",name);
	while(getchar() != '\n');
	p = find_name_bef_student_node(head,name);
	if(NULL == p)
	{
		printf("no find data!!\n");
		return;
	}//注意这里的处理 昨晚根本没注意到！！重大失误！！！
	p = p->next;
	
	printf("请输入学号:");
	scanf("%d",&p->stu.ID);
	printf("请输入姓名:");
	scanf("%s",p->stu.name);
	while(getchar() != '\n');
	
	printf("请依次输入英语、数学、语文成绩:\n");
	scanf("%f%f%f",&p->stu.mark.english,
				   &p->stu.mark.math,
				   &p->stu.mark.chinese
	);
	while(getchar() != '\n');
	
	p->stu.mark.grade_sum = p->stu.mark.chinese
							+p->stu.mark.math
							+p->stu.mark.chinese;
}

/*
	排序 总成绩
*/
void csort_gradesum_student_node(struct stu_node * head)
{
	struct stu_node * temp = NULL;//下一个
	struct stu_node * bef = NULL;//前一个
	int num = 0;//次数
	int i = 0;
	int j = 0;
	int flag = 0;//用于改进冒泡法
	
	if(NULL == head)
	{
		printf("in is null\n");
		return;
	}
	bef = head;
	while(bef->next != NULL)
	{
		bef = bef->next;
		num++;
	}//num次

	for(i = 0;i< num-1;i++)
	{
		bef = head;
		temp = bef->next;//冒泡法本质是两个相邻的比较 满足交换 别和选择法混淆！！xiaofan！！！所以这里只要把节点指针复位就行了
		flag = 1;
		for(j=0;j < num-i-1;j++)//冒泡法
		{
			if( (temp->stu.mark.grade_sum) < (temp->next->stu.mark.grade_sum))
			{
				bef->next = temp->next;
				temp->next = bef->next->next;
				bef->next->next = temp;
				flag = 0;
			}
			bef = bef->next;
			temp = bef->next;
			
			if(flag)//如果不再有数据交换了 说明顺序已经排好了^_^可以退出
			{
				break;
			}	
		}
	}	
}

/*
	删除 每次删1个
*/
void del_name_student_node(struct stu_node * head)
{
	struct stu_node * bef = NULL;//前一个
	struct stu_node * temp = NULL;//当前
	char name[20] = "";
	if(NULL == head)
	{
		printf("in is null\n");
		return;
	}
	printf("请输入要修改的姓名：");
	scanf("%s",name);
	while(getchar() != '\n');
	bef = find_name_bef_student_node(head,name);
	if(NULL == bef)
	{
		printf("no find data!!\n");
		return;
	}//注意这里的处理 昨晚根本没注意到！！重大失误！！！
	temp = bef->next;
	
	bef->next = temp->next;
	
	free(temp);
	temp = NULL;
}
/*
	释放
*/
void free_file_student_node(struct stu_node * head)
{
	struct stu_node * bef = NULL;//前一个
	struct stu_node * temp = NULL;//当前
	
	if(NULL == head)
	{
		printf("in is null\n");
		return;
	}

	bef = head->next;
	while(NULL != bef)
	{
		temp = bef->next;
		free(bef);
		bef	= temp;
	}
	//v.node 11-17-23:22
}



