/*
 * 
 *
 * project: hw4
 * name: 
 * user??
 * date: 
 * file: test.c
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"

/*
 * This is the driver test for testing your implementation
 * Do not modify the code below
 */

void str_test();
void num_test();
void comment_test();

int main(void){   

    str_test();
    num_test();
    comment_test();

  return 0;
}


void str_test(){

    FILE *file_str;
    file_str = fopen("../str_hw4.txt", "r");

    char s[100], s1[50], s2[50];
    int i=0,j=0;
    while ((fgets(s,100, file_str)) != NULL){

        if (s[0]=='\n' || s[0]=='#') continue;
        
        while (s[i] != ','){
            s1[i] = s[i];
            i++;
        }
        s1[i++] = 0;

        while (s[i] != '\n' && s[i] != EOF){
            s2[j++] = s[i++];
        }
        s2[j] = 0;
        printf("s1: %s\t s2: %s\t Postion: %d\t",s1,s2,any(s1,s2));
        squeeze(s1,s2);
        printf("Squeezed s1: %s\n", s1);

        i = j = 0;

    }


     fclose(file_str);
}


void num_test(){

    printf("\n");

    FILE *file_num;
    file_num = fopen("../num_hw4.txt", "r");
    char s[100];
    unsigned int num, n, p;
    while ((fgets(s,100, file_num)) != NULL){

        if (s[0]=='\n' || s[0]=='#') continue;
        sscanf(s,"%u,%u,%u",&num, &n, &p);
        printf("num is: %u\t right rotate %u bits is: %u \t" 
                "invert at %u with %u right_ajusted bits is: %u\n",
                 num,n, rightrot(num,n),p,n, invert(num,p,n));

    }

     fclose(file_num);
}


void comment_test(){

    printf("\n");

    FILE *file;
    file = fopen("../comments.txt", "r");
    char c;
    printf("Original text is:\n");
    while ((c=getc(file)) != EOF) putchar(c);
    fclose(file);
    printf("!!!After removing comments is:!!!\n");

    remove_comments();

}