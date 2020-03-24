/*
 *
 * project: hw2
 * name: Jimmy Tran
 * account: jimmyt16@users.cs.umb.edu
 * date: 2/26/2020
 * file: conversion.c
 * notes: I added and defined some extra functions such as getFraction(), strrev()
 *
 *   
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/*function to combine the integer and fraction part (integer.fraction)*/ 
float turnToFloat(int,int);
/*function to return fraction segment of float*/ 
float getFraction(float);
/*function to return the reversed string*/ 
char* strrev(char*);
/* this function converts the integer num into a q_based string */
void num2q(int , char [], int );
/* this function converts a q_based string into an integer */
int q2num(char [], int );
/* this function converts the float f into a binary string fb[]*/
void f2b(float, char[]);
/* this function converts the binary string fb[] into a float */
float b2f(char[]);
// we will find the length of the the digits before the (.) and the length after
//seperate the integer and fraction part of the float into two seperate variables
float b2f(char str[]){
    char int_str[20]="";
    char frac_str[20]="";
    int_str[0] = '\0';
    frac_str[0] = '\0';
    int i = 0;
    int counting = 0;
    int running_total_int = 0; 
    int running_total_frac = 0; 
    int multiple;
    
    for(i = 0; i < strlen(str);i++){ /* Get the Integer segement of the float*/
        if(str[i]=='.'){
            break;
        }
        int_str[i] = str[i];
    }
    for(int counter = i+1; counter < strlen(str); counter++){ /* Get the fraction segement of the float*/
        frac_str[counting] = str[counter];
        counting++;
    }
    int degree = strlen(int_str);
    for(int c = 0;c<strlen(int_str);c++){ /*Get the Integer rep of the fraction string binary*/
        multiple = int_str[c]-'0'; 
        running_total_int = running_total_int + (pow(2,--degree)*multiple);
    }
    degree = strlen(frac_str); 
    for(int l = 0; l<degree;l++){ /*Get the Integer rep of the fraction string binary*/
        multiple = frac_str[l] -'0';
        running_total_frac = running_total_frac + (pow(2,--degree)*multiple);
    }   
    float number_representation = turnToFloat(running_total_int,running_total_frac); /*call function concat the two strings and convert to a float*/
    return number_representation;
}
int q2num(char q_string[], int base_q){
    // int the_base = base_q;
    int running_total = 0;
    int degree = strlen(q_string);
    for(int counter = 0;counter<strlen(q_string);counter++){
        int multiple = q_string[counter]-'0'; //convert to int from char
        running_total = running_total + (pow(base_q,--degree)*multiple);
    }
    return running_total;
}
void num2q(int num, char num_q[], int q){
    num_q[0] = '\0';
    char str[10];
    int current = num;
    while(current != 0){
        int remainder = current%q;
        sprintf(str, "%d", remainder);
        strcat(num_q,str);
        current = current/q;
    }
    char *finalStr = strrev(num_q);
    num_q = finalStr;
}
void f2b(float f, char str[]){
    str[0] = '\0';  //reset the string
	int integer_rep = f;
	float frac_rep = getFraction(f);
    //FRAC TO BIN
    char fracstr[25]="."; //declares a string with decimal to represent the fraction part of the float
	float current = frac_rep;
	int int_value = 0;
	float float_value = frac_rep;
	while(float_value > 0.00){ 
		current = current * 2;
		int_value = current;
		current = float_value = getFraction(current);
		if(int_value == 0){
			strcat(fracstr,"0");
		}else if(int_value == 1){
			strcat(fracstr,"1");
		}
	}
    // INT TO BIN
    char intStr[10]; //declares an empty string  
	while(integer_rep>0){
		int remainder = integer_rep%2;
		if(remainder ==0){
			strcat(intStr,"0");
		}
		else if(remainder ==1){
			strcat(intStr,"1");
		}
		integer_rep = integer_rep/2;
	}
	char * newString = strrev(intStr); //reverses the binary string 

	strcat(str,newString); //concatanate the integer binary with the fraction binary
	strcat(str,fracstr); // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
}

float turnToFloat(int in, int fr){
    char f1[20];
    char f2[20];
    sprintf(f1,"%d",in);
    sprintf(f2,"%d",fr);
    strcat(f1,".");
    strcat(f1,f2);
    float float_rep = atof(f1);
    return float_rep;
}
float getFraction(float fl){
	fl = fl -(long)fl;
	return fl;
}
/* this function can print out an q_string s[]*/
void print(char s[], int q){

    printf(" %2d-string: ", q);
    for (int i=0;s[i]; i++){
        if (!((i)%4)&&i!=0) printf("|");
        printf("%c", s[i]);
    }
    printf("\n");
}
/* Read bits into a char array 
*  from memory of a 32-bit data type
*/
void bin_char(unsigned n, char s[]) 
{ 
    unsigned i, j=0; 
    for (i = 1 << 31; i > 0; i = i / 2) {
        s[j++] = (n & i)?  '1' : '0';
    }
    s[j] = 0;
}
//func to reverse the string (string.h func strrev() does not work)
char *strrev(char *str){
      char *p1, *p2;
      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int main(void)
{
    char num_q[100];
    int  num = 2020;
    // this loop converts num into string num_q and print out  
    for (int i=2; i<16; i++){
        num2q(num, num_q, i);
        print(num_q, i);
        printf("       num: %d\n\n", q2num(num_q,i));
    }
    char fb[32];
    // this loop converts f into binary string fb[]       
    for (int i=-10;i<4;i++){
        float f = (float) pow(2,i); 
        f2b(f,fb);
        printf("pow(2,%2d)f: %g\n",i, f);
        print(fb,2);
        printf("pow(2,%2d)f: %g\n\n",i, b2f(fb));
    }
    float f = 127 + 0.1; 
    f2b(f,fb);
    printf("        f: %g\n", f);
    print(fb,2);
    printf("        f: %g\n\n", b2f(fb));  
}

