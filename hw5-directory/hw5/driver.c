/*
 * 
 *
 * project: hw5
 * name: 
 * user??
 * date: 
 * file: test.c
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>
#include "hw5.h"

/*
 * This is the driver test for testing your implementation
 * Do not modify the code below
 */



int main(void){   

    char *t1 = "../num.txt";
    char *t2 = "../str.txt";
    char *t3 = "../CompleteShakespeare.txt";

    int *nums, num, num_w, num_l;
    char *words[MAX_W], *lines[MAX_L];

    nums = malloc(MAX_C*4);
    for (int i=0;i<MAX_W;i++)
        words[i] = malloc(MAX_C);

    for (int i=0;i<MAX_L;i++)
        lines[i] = malloc(MAX_C);



    num = intff(t1,nums);
	
    for (int i=0;i<num;i++){

        printf("Number %d \tis palindrome or not : %d\n",
                nums[i], isPalindrome(nums[i]));
    }
    

    printf("\n");


    num_l = linesff(t2, lines);

    for (int i=0;i<num_l;i++){
        num_w = wordsfs(lines[i], words); //passing in the first word in lines, and 
        printf("\"%s\": Common Prefix is: %s\n------------\n",
                lines[i], longestCommonPrefix(words, num_w));
    }


    for (int i=0;i<MAX_W;i++) free(words[i]);
    for (int i=0;i<MAX_L;i++) free(lines[i]);
    
    tail(t3, nums[0]);
    
    free(nums);

  return 0;
}