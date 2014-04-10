#ifndef PERSON_H
#define PERSON_H 1
typedef enum Bool{true=1,false=0}bool;
typedef struct Person{
	char name[20];
	bool gender;
	int age;
	double salary;
}person;
//struct Person是一个结构类型
#endif
