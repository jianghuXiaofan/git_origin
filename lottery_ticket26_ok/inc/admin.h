#ifndef __ADMIN_H
#define __ADMIN_H

void admin_select_control(void);
void Admin_addpay(struct User * User_head);
void Admin_find_uesr_control(struct User * User_head);

void Admin_Publish_ticket(void);

void Admin_find_name_show(struct User * User_head);
void Admin_find_inter_show(struct User * User_head);


void Admin_sort_uesr_control(struct User * User_head);

//为彩民解冻
void Admin_release_user(struct User * User_head);

void Admin_sort_name_show(struct User * User_head);
void Admin_sort_money_show(struct User * User_head);
#endif
