/*
 *
 * name: Jimmy Tran
 * user jimmyt16@users.cs.umb.edu
 * date:
 * file: driver.c
 */
#include "hw8.h"
#include <stdio.h>
#include <string.h>

float min(float,float); //func to get min of two floats
float max(float,float); //get max of two flaots
float getWeightedScore(float *); //get the weighted scores of homework combined with tests
void printcsv(); //function to print the sorted students

void readStudent(Student *stu, char *s){ //read the character s (line inside the csv) and update the Student structure
	char *pt;
	pt = strtok (s,","); //divides the pt string into tokens seperated by ','
  int index = stu->len; //set current len of student structure to be the index
	//allocate first,last,id,and grades array[]
  stu[index].firstname = malloc(NAME_LEN*sizeof(char));
  stu[index].lastname = malloc(NAME_LEN*sizeof(char));
  stu[index].id = malloc(ID_LEN*sizeof(char));
  stu[index].grades = calloc(NUM_GRADES,sizeof(float));
  while (pt != NULL) { //pass student's name, homework , and test grades onto the student struct
      strcpy(stu[index].firstname,pt);pt = strtok (NULL, ",");
			strcpy(stu[index].lastname,pt);pt = strtok (NULL, ",");
			strcpy(stu[index].id,pt);pt = strtok (NULL, ",");
			stu[index].grades[0] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[1] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[2] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[3] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[4] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[5] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[6] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[7] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[8] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[9] = atof(pt);pt = strtok (NULL, ",");
			stu[index].grades[10] = atof(pt);pt = strtok (NULL, ",");
  }
  stu[index].weighted = getWeightedScore(stu[index].grades); //get the weighted total and store it inside the student struct, passsing in the grades array
}

Class * readClass(char *s){ //reads from the csv file 's' to create a Class pointer variable and returns it with students data
	FILE *file = fopen(s,"r");
	Class *cl = malloc(12*sizeof(char));
  cl->stus = calloc(MAX_STUDENTS,sizeof(Student)); //allocate the stus for 20 arrays
  cl->stus = malloc(sizeof(Student)); //allocate memory for stus
  int c = 0;
	char buf[1024]; //declare a char array with size 1024 bytes
	while (fgets(buf, 1024, file)) { //get the string from the csv line by line and pass it into the readStudent()
    cl->stus->len = c++; //increment the length of the students inside the Student struct
		readStudent(cl->stus,buf);
    }
	return cl;
}

void sortClass(Class * class){ //sort the classes based on the weighted grades of students from the
  printf("inside sortClass()\n");
  FILE *file  = fopen("sorted.csv","w");
  int i,j;
  int n = class->stus->len + 1;
  Student *temp = malloc(sizeof(Student));
    for(i=1;i<n;i++) //sort the students by the weighted grades
    {
        for(j=0;j<n-i;j++)
        {
            if(class->stus[j].weighted > class->stus[j+1].weighted)
            {
                *temp = class->stus[j];
                class->stus[j] =class->stus[j+1];
                class->stus[j+1] = *temp;
            }
        }
  
    }
  for(int i = 0;i<n;i++){ //iterate through the student objects within the struct class
    //write to file
    fprintf(file,"%s,%s,%s,%.0f,%.0f,%.0f,%.0f,%.0f,%.0f,%.0f,%.0f,%.0f,%.0f,%.0f,%.1f\n",class->stus[i].firstname,class->stus[i].lastname,class->stus[i].id,
		class->stus[i].grades[0],class->stus[i].grades[1],class->stus[i].grades[2],class->stus[i].grades[3],class->stus[i].grades[4],class->stus[i].grades[5],
		class->stus[i].grades[6],class->stus[i].grades[7],class->stus[i].grades[8],class->stus[i].grades[9],class->stus[i].grades[10],class->stus[i].weighted);
  }
  free(temp); //free the temp variable
	fclose(file); //close file
	printcsv(); //call to print sorted students on console
}

void printcsv(){
	printf("INSIDE PRINTCSV()\n\n");
	FILE *file = fopen("sorted.csv","r"); //opens up the sorted.csv file
	char buff[1024];
	while(fgets(buff,1024,file)!=NULL){
		printf("%s",buff); //prints out line by line
	}
	fclose(file);
}

void freeClass(Class * c){
  printf("\nINSIDE freeClass()\n");
  free(c); //free class struct
  exit(0);
}

float getWeightedScore(float *g){
	printf("INSIDE getWeightedScore()\n");
  float hw_average= 0;
  for(int counter=0;counter<8;counter++){ //calculate all the homework scores and get 5% of it
    hw_average += g[counter];
  }
  hw_average = hw_average * 0.05;//get 5% of all added hw scores

  //get the minimum and maximum score of test3 vs test1,test2
  float maximum = max(g[10],max(g[8],g[9])) * 0.35;
  float minimum = min(g[10],max(g[8],g[9])) * 0.25;
  return (hw_average + maximum + minimum); //return weighted score
}

float max(float num1,float num2){
  return (num1 > num2 ) ? num1 : num2;
}
float min(float num1, float num2) {
  return (num1 > num2 ) ? num2 : num1;
}
