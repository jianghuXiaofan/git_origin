#ifndef __STRUCT_H
#define __STRUCT_H

struct score
{
	float chinese;
	float math;
	float english;
	float grade_sum;
};

struct student
{
	int ID;
	char name[20];
	char classroom[20];
	int age;

	struct score mark;
};

struct stu_node
{
	struct student stu;
	struct stu_node * next;
};

#endif
