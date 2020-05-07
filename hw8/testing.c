#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main(){
	// char str[] ="jimmy,tran,3,4,5";
	// char *pt;
	// pt = strtok (str,",");
  //   while (pt != NULL) {
  //       printf("%s\n", pt);
  //       pt = strtok (NULL, ",");
  //   }
	//
	// FILE *file = fopen("cs240.csv","r");
	// char buf[1024];
	// while (fgets(buf, 1024, file)) {
  //       printf("%s\n", buf);
  //   }
	// fclose(file);
	float *arr;
	arr = calloc(12,sizeof(float));
	arr = {20,90,90,90,90,90,90,90,90,90,90};
	float weighted = getWeightedScore(arr);
	printf("THE WEIGHTED: %f\n",weighted);

}

float getWeightedScore(float *g){
  int counter = 0;
  float hw_average;
  float test_average;
  for(counter=0;counter<8;counter++){ //calculate all the homework scores and get 5% of it
    hw_average = hw_average + g[counter];
  }
  hw_average = hw_average * 0.05;//get 5% of all added hw scores

  //get the minimum and maximum score of test3 vs test1,test2
  float maximum = max(g[10],max(g[8],g[9])) * 0.35;
  float minimum = min(g[10],max(g[8],g[9])) * 0.25;

  return (hw_average + maximum + minimum); //return weighted score
}

/**
 * Find maximum between two numbers.
 */
float max(float num1, float num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

/**
 * Find minimum between two numbers.
 */
float min(float num1, float num2)
{
    return (num1 > num2 ) ? num2 : num1;
}
