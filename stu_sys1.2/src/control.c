#include "control.h"
#include "top_view.h"
#include <stdio.h>
#include <stdlib.h>
#include "fun_login.h"
#include "struct.h"
#include "link.h"
#include "file_wr_rd.h"


void login_control(void)
{
	char choose = 0;
	while(1)
	{
		system("clear");
		login_view();
		choose = getchar();
		while(getchar() != '\n');
		switch(choose)
		{
		case '1':
			login();
			//printf("login!\n");
			break;
		case '2':
			printf("register\n");
			break;
		case '0':
			printf("exit\n");
			return ;
		default:
			printf("input erro!\n");
			//return ;
		}
	}
}

void fun_teach_view(void)
{
	char choose = 0;
	system("clear");
	struct stu_node * head = malloc(sizeof(struct stu_node));
	if(NULL == head)
	{
		printf("分配空间失败\n");//学长提示 这样更好些！确实有分配不出空间的情况
		return;
	}
	head->next = NULL;
	file_read(head);//读
	while(1)
	{
		printf("1查看2增加3查找4修改5排序6删除0保存退出\n");
		choose = getchar();
		while(getchar() != '\n');
		switch(choose)
		{
			case '1':
					printf("查看\n");
					output_show(head);
				break;
			case '2':
					printf("增加\n");
					insert_student_node(head);
				break;
			case '3':
					printf("查找\n");
					find_name_now_student_node(head);
					break;
			case '4':
					printf("修改\n");
					xiugai_name_student_node(head);
					break;
			case '5':
					printf("排序\n");
					csort_gradesum_student_node(head);
					break;
			case '6':
					printf("删除\n");
					del_name_student_node(head);
					break;
			case '0':
					printf("退出\n");
					file_write(head);//这样避免多次读写 但缺陷是中途异常退出 就麻烦了^_^
					//可以释放了 学生查询的再开一条链表
					free_file_student_node(head);
					free(head);
					head = NULL;
				   return;
				   break;
			default: printf("input error\n");
		}
	}
}

void fun_student_view(void)
{
	char choose = 0;
	system("clear");
	
	struct stu_node * head = malloc(sizeof(struct stu_node));
	if(NULL == head)
	{
		printf("分配空间失败\n");//学长提示 这样更好些！确实有分配不出空间的情况
		return;
	}
	head->next = NULL;

	file_read(head);//读
	while(1)
	{
		printf("1查看成绩2修改密码0保存退出\n");
		choose = getchar();
		while(getchar() != '\n');
		switch(choose)
		{
			case '1':
					printf("查看\n");
					//find_name_now_student_node(head);//把这个改了 
					output_show(head);//^__^查看全部了，，，果然没注册
				break;
			case '2':
					printf("修改密码，有待添加亲！\n");
				break;
			case '0':
					printf("保存退出\n");
					free_file_student_node(head);
					free(head);
					head = NULL;
				   return;
				   break;
			default: printf("input error\n");
		}
	}
}



