#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int any(char[],char[]);

void main(){
	printf("THIS IS THE POSITION : %d\n",any("jimmy","killa"));
}
int any(char s1[],char s2[]){
	for(int x = 0;x< strlen(s1);x++){
		for(int i = 0;i<strlen(s2);i++){
			if(s1[x] == s2[i]){
				return i;
			}
		}
	}
	return -1;	
}


