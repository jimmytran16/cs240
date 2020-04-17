    
/*
 * 
 *
 * project: hw5
 * name: Jimmy Tran
 * user: jimmyt16@users.cs.umb.edu
 * date: 4/16/2020
 * file: hw5.c
 * notes: added some helper functions into the code
 */

#include "hw5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

char** str_split( const char* , const char );
long fsize(FILE* binaryStream); 
char* fgetsr(char*,int,FILE*);

/* File must be open with 'b' in the mode parameter to fopen() */
/* Set file position to size of file before reading last line of file */

//30 points
void strip(char *s){
	char *RECORD = s; //store the string into a record variable
	int c,x;  
    for (c = 0, x = 0; c<strlen(s); c++,x++)          
    {
        if (s[c]!='\t'&&s[c]!=' '&&s[c]!='\n')   //if there is no space/tabs/newline then assign the current character to the records array                        
            RECORD[x]=s[c];                     
        else
            x--;                       //else decrement the element x               
    }
    s = RECORD;
	RECORD[x]=0;
	strcpy(s, RECORD);
	
    //printf("NEW STRING: %s",s);
	
}
// 30 points
int intff(const char *s, int *nums){
    FILE *file;						//Open file
    file = fopen(s, "r");
    if(file == NULL)
	    exit(1);

    int temp, count = 0;
    while(fscanf(file, "%d%*c", &temp) == 1){
		*(nums + count++) = temp;
	nums = realloc(nums, sizeof(int) * (10));
    }

    fclose(file);					//Close file
    return count;					//Return num count
}

// 30 points
int linesff(const char *s, char **lines){
    FILE* file = fopen(s, "r"); /* should check the result */
    file = fopen(s,"r");
    char line[30];
    int counter = 0;

    while (fgets(line,sizeof(line) , file)!=NULL) {
	if (line[0]=='\n'||line[0]=='\t'){
	continue;}
	else if(strspn(line, " \r\n") == strlen(line))
	{continue;}
	    strip(line); //Strip the line
	    strcpy(lines[counter++], line);
    }
    return counter;
}
//function to split a string

// 30 points
int wordsfs(const char *s, char **words){
	char *RECORD;
    char *s2 = malloc(sizeof(s)); //ALLOCATE A POINTER CHAR VAR TO the size of string s
    int count = 0; //set a counter 
    strcpy(s2, s);
    RECORD = strtok(s2, ",");
    while(RECORD != NULL){
	strcpy(*(words + count++), RECORD);
	RECORD = strtok(NULL, ",");
    }
    return count;
}

// 30 points
char * longestCommonPrefix(char ** words, int wordsSize){
	int j = 0;
    char* VAR = malloc(20 * sizeof *VAR);//ALLOCATE the P pointer to size 20 
    char RESULT[10] = ""; //init a char array
    int THE_LENGTH = strlen(RESULT);
    while(j < strlen(words[0])){
        if(wordsSize == 4){ //if the wordSize is 4 then compare four words
			if(words[0][j] == words[1][j] && words[1][j] == words[2][j] &&words[2][j]== words[3][j]){ 
            RESULT[THE_LENGTH++] = words[0][j];} //if char in the strings match, then append to the RESULT array
        }
		else{ //if the wordSize is 3 then compare three words at a time
			if(words[0][j] == words[1][j] && words[1][j] == words[2][j]){ 
            RESULT[THE_LENGTH++] = words[0][j];} //if char in the strings match, then append to the RESULT array
        }
        j++;
    }
    RESULT[THE_LENGTH] = '\0'; //set the last element in the array to be null
	VAR[strlen(VAR)] = '\0'; // make the last element of the p array to be null
    strcpy(VAR, RESULT);
	//printf("THE P: %s\n",RESULT);
    return VAR;

}
// 30 points
int isPalindrome(int x){
	int sum = 0;
	int r;
	int TEMP;
	int THE_NUMBER = x; //get the value passed in and assign it to the_number variable
	TEMP = THE_NUMBER; //assign a variable to preserve the VALUE of the initial integer value
	//Reversing the integer and comparing it to the original integer
	while(x>0){  
		r = x%10; //get the remainder of the integer
		sum=(sum*10)+r;
		x=x/10;
	}
	if(TEMP==sum){// if the reverse integer is equals to the initial one , then return 1
		return 1;
	}
	return 0;
}
//40 points
void tail(const char *s, int n){
    char array[n][256];

    FILE *file;
    file = fopen(s, "rb");
    if(file == NULL)
	exit(1);

    long sz = fsize(file);
    if(sz > 0) {
	char buf[256];
	fseek(file, sz, SEEK_SET);
	for(int i = 0; i < n; i++){
	    fgetsr(buf, sizeof(buf), file);
	    strcpy(array[i], buf);
	}
    }

    for(int i = n; i >= 0; i--) {
	printf("    %s", array[i - 1]);
   }

    fclose(file);
    return;
}
char* fgetsr(char* buf, int n, FILE* binaryStream) {
  long fpos;
  int cpos;
  int first = 1;

  if (n <= 1 || (fpos = ftell(binaryStream)) == -1 || fpos == 0)
    return NULL;

  cpos = n - 1;
  buf[cpos] = '\0';

  for (;;) {
    int c;

    if (fseek(binaryStream, --fpos, SEEK_SET) != 0 || (c = fgetc(binaryStream)) == EOF)
      return NULL;

    if (c == '\n' && first == 0) /* accept at most one '\n' */
      break;
    first = 0;

    if (c != '\r') {
      unsigned char ch = c;
      if (cpos == 0) {
        memmove(buf + 1, buf, n - 2);
        ++cpos;
      }
      memcpy(buf + --cpos, &ch, 1);
    }

    if (fpos == 0) {
      fseek(binaryStream, 0, SEEK_SET);
      break;
    }
  }
  memmove(buf, buf + cpos, n - cpos);
  return buf;
}

long fsize(FILE* binaryStream) {
  long ofs, ofs2;
  int result;

  if (fseek(binaryStream, 0, SEEK_SET) != 0 || fgetc(binaryStream) == EOF)
    return 0;

  ofs = 1;

  while ((result = fseek(binaryStream, ofs, SEEK_SET)) == 0 &&
         (result = (fgetc(binaryStream) == EOF)) == 0 && ofs <= LONG_MAX / 4 + 1)
    ofs *= 2;

  /* If the last seek failed, back up to the last successfully seekable offset */
  if (result != 0)
    ofs /= 2;

  for (ofs2 = ofs / 2; ofs2 != 0; ofs2 /= 2)
    if (fseek(binaryStream, ofs + ofs2, SEEK_SET) == 0 && fgetc(binaryStream) != EOF)
      ofs += ofs2;

  /* Return -1 for files longer than LONG_MAX */
  if (ofs == LONG_MAX)
    return -1;

  return ofs + 1;
}