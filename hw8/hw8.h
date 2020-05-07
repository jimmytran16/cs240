#ifndef HW8_H
#define HW8_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <getopt.h>
#ifndef TEST_FILE
#define TEST_FILE(f,s,s1) 	\
		if (NULL==f){		\
			fprintf(stderr, "%s: can't open %s\n", s,s1);\
			exit(1);}
#endif


#ifndef TEST_NULL
#define TEST_NULL(p,s) \
		if (p == NULL){ \
			printf("Pointer %s is NULL\n",s); \
			exit(EXIT_FAILURE); }
#endif

#define NAME_LEN 20
#define ID_LEN 4
#define NUM_GRADES 12
#define MAX_LINE 200
#define INDEX_SORT 11
#define MAX_STUDENTS 100


typedef struct
{
	char *firstname, *lastname, *id;
	float *grades;
	int len;
	float weighted;
} Student;


typedef struct
{
	Student *stus; int len, num;
} Class;


void readStudent(Student *stu, char *s);
Class * readClass(char *);
void sortClass(Class *);
void freeClass(Class *);


#endif
