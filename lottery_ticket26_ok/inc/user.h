/*************************************************************************
    > File Name: inc/user.h
    > Author: xiaofan
    > Mail: jianghu_xiaofan@foxmail.com 
    > Created Time: 2016��11��22�� ���ڶ� 15ʱ17��52��
 ************************************************************************/

#ifndef __USER_H
#define __USER_H

void user_regist(struct User * User_head);
void user_login(struct User * User_head);
void user_logout(struct User * User_head);
void user_mess_view(struct User * User_message_node);
#endif
