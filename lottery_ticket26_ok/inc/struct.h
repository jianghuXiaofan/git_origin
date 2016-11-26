/*************************************************************************
    > File Name: inc/struct.h
    > Author: xiaofan
    > Mail: jianghu_xiaofan@foxmail.com 
    > Created Time: 2016Äê11ÔÂ22ÈÕ ÐÇÆÚ¶þ 13Ê±39·Ö44Ãë
 ************************************************************************/
#ifndef __STRUCT_H
#define __STRUCT_H
//用户结构体
struct User
{
	char name[30];
	char pwd[50];
	float money;
	char flag;
	struct User * next;
};
//发行彩票结构体
struct Publish_ticket
{
	int issue;
	float price;
	int num[4];//3个号码
	char state;
	int sellCount;
	float totalMoney;
	struct Publish_ticket * next; 
};

struct Buy_ticket
{
	int issue;//购买期号
	int ID;//唯一id
	int	buyNum[4];
	int zhushu;//注数 5
	char owner[30];
	char statue;
	float money;
	struct Buy_ticket * next;
};
#endif

