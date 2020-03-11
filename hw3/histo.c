/*
 *
 * project: hw3
 * name: Jimmy Tran
 * account: jimmyt16@users.cs.umb.edu			
 * date: 03/07/2020
 * file: histo.c
 * notes: 
 *
    
 *   
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
#define MAX_CHAR 100

// func to get the longest string from the file
char * getBiggestString(char[]);
// func to get the pointer of duplicate rep of a string
char *ft_strdup(char*);
// func to get the occurances of strings with specfic length(1-27)
void getCountOfOccurs(char[], int[]);


char * getBiggestString(char str[]){
	char theString[MAX_CHAR] = "";
	char longestString[MAX_CHAR] = "";
	for(int x = 0;  x < strlen(str); x++){
		if(isalpha(str[x]) == 0 && isdigit(str[x]) == 0){ //check if its a letter / digits
			if(strlen(theString)>strlen(longestString)){ //check if the record string is longer than record string
				longestString[0] = '\0'; //empty out the longest string
				strcpy(longestString,theString); //cpy record string into the longest string
				theString[0] = '\0'; //clear the record string
			}else{	
				theString[0] = '\0'; //clear the record string
			}
			continue;
		}
		strncat(theString,&str[x],1);
	}
	return ft_strdup(longestString);
}

void getCountOfOccurs(char s[], int a[]){
	char ss1[MAX];
	ss1[0] = '\0';
	for(int x = 0;  x < strlen(s); x++){
		if(isalpha(s[x]) == 0 && isdigit(s[x]) == 0){
			int element = strlen(ss1);
			a[element-1] = a[element-1] + 1;
			ss1[0] = '\0'; //clearing up the string because the current word just ended
			continue; // continue to avoid concatenation of special characters
		}	
		strncat(ss1,&s[x],1);		
	}
}

// return pointer of null-terminated string
char *ft_strdup(char *src)
{
    char *str;
    char *p;
    int len = 0;

    while (src[len])
        len++;
    str = malloc(len + 1);
    p = str;
    while (*src)
        *p++ = *src++;
    *p = '\0';
    return str;
}
/*Complete the program*/
int main(void)
{    
	char longString[MAX]="";
    char buf[MAX_CHAR]; 
	int a[26]; 
	// give all values of the elements in array 0
	for(int op = 0; op<26;op++){
		a[op] = 0;
	}
	// getting the stream of the input file
	while(fgets(buf,MAX,stdin)){
		char * currentString = getBiggestString(buf); // call getBiggestString to proccess the line and try to find the longest string 
		if(strlen(currentString)>strlen(longString)){ 
			longString[0] = '\0';
			strcpy(longString,currentString);
		}
	}
	// open the textfile to read into
	FILE *fptr = fopen("CompleteShakespeare.txt","r");
	char buffer[MAX];
	while(fgets(buffer,MAX,fptr)){
		getCountOfOccurs(buffer,a);
	}
	fclose(fptr);
	printf("%s\n",longString);
	for(int s = 0; s<27; s++){
		printf("\n%2d %6d ",s+1,a[s]);
		int ASTERISK_COUNT = 0;
		//check if the value of the array is 0, if it is that means we don't print any asterisks
		//ASTERISK COUNT to print out the amount of * (1 by each 4000 words)
		ASTERISK_COUNT = (a[s]/4000) + 1;
		if(a[s] == 0){ //if the value of word count is 0, then dont print out any '*'
			ASTERISK_COUNT = 0;
		}
		//print the asterisks
		for(int f=0; f < ASTERISK_COUNT;f++){
			printf("*");
		}
	}

    return 0;   
}

