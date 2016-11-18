#ifndef __LINK_H
#define __LINK_H

void insert_student_node(struct stu_node * head);
void output_show(struct stu_node * head);
//按姓名查找前一个
struct stu_node * find_name_bef_student_node(struct stu_node * head,char * name);
void find_name_now_student_node(struct stu_node * head);
//按姓名 修改整个信息重写 
void xiugai_name_student_node(struct stu_node * head);

void csort_gradesum_student_node(struct stu_node * head);

void del_name_student_node(struct stu_node * head);

void free_file_student_node(struct stu_node * head);
#endif
