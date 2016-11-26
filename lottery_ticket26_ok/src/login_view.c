/*:************************************************************************
    > File Name: src/login_view.c
    > Author: xiaofan
    > Mail: jianghu_xiaofan@foxmail.com 
    > Created Time: 2016年11月21日 星期一 22时06分12秒
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "login_view.h"
#include "control.h"


void login_view(void)
{
	system("clear");
	printf("**********彩票系统**********\n");
	printf("***********主菜单***********\n");
	printf("**\t1.管理员\n");
	printf("**\t2.用户\n");
	printf("**\t3.公正员\n");
	printf("**\t0.exit\n");
	printf("****************************\n");
	printf("请选择: ");
}

void admin_login_view(void)
{
	system("clear");
	printf("*********管理员菜单*********\n");
	printf("**\t1.查看彩民信息\n");
	printf("**\t2.发行下一批彩票\n");
	printf("**\t3.为彩民充值\n");
	printf("**\t4.排序\n");
	printf("**\t5.为彩民解冻\n");
	printf("**\t0.exit\n");
	printf("****************************\n");
	printf("请选择: ");
	
}

void user_login_view(void)
{
	system("clear");
	printf("**********用户菜单**********\n");
	printf("**\t1.注册\n");
	printf("**\t2.登陆\n");
	printf("**\t3.注销\n");
	printf("**\t0.exit\n");
	printf("****************************\n");
	printf("请选择: ");
}

void gref_login_view(void)
{
	system("clear");
	printf("*********公正员菜单*********\n");
	printf("**\t1.开奖\n");
	printf("**\t2.查询彩票\n");
	printf("**\t0.exit\n");
	printf("****************************\n");
	printf("请选择: ");
}

