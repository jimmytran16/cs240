/*
 * 
 * 
 * project: hw4
 * name: Jimmy Tran 
 * user??
 * date: 3/26/2020 
 * file: hw4.c
 * notes: added some helper functions --- removeChar() , incomment(), check_quote(), and lengthOfWord()
 *  
 */
 
#include <stdio.h>
#include <string.h>
#define MAX_STRING 20
#define ASTERISK_CHAR '*'
#define FORWARD_SLASH '\\'
#define BACK_SLASH '/'
#define QUOTE '"'

void removeChar(char *, char); // function to remove a char from a string
//--- helper functions
void char_removal(int c); // function to remove the character
void incomment(void);
void check_quote(int c);
int lengthOfWord(void);


// 30 points
// Write the function any(s1,s2) , which
// returns the first location in a string s1 where any
// character from the
// string s2 occurs, or -1 if s1 contains no characters
// from s2 . (The standard library function strpbrk does 
// the same job but  returns a pointer to the location.)

int any(char s1[], char s2[]){
	for(int x = 0;x< strlen(s1);x++){
		for(int i = 0;i<strlen(s2);i++){
			if(s1[x] == s2[i]){
				return i;
			}
		}
	}
	return -1;	
}

// 30 points

// Write squeeze(s1,s2)
// that deletes each character in s1 that matches any character 
// in the string s2 .

void squeeze(char s1[], char s2[]){
	char recordString [MAX_STRING];
	recordString[0] = '\0'; //keep a record of the string
	strcpy(recordString,s1);
	for(int i =0 ; i<strlen(recordString);i++){ //iterate through the recordstring ...
		for(int x = 0; x < strlen(s2); x++){ // iterates through all of the characters in the s2 on every iteration of the first string
			if( recordString[i] == s2[x]){ //checks if the current s1 character is equal to s2 character
				removeChar(s1,s2[x]); // if yes then remove the char from the s1 char array
			}
		}
	}
}

// 30 points

// Write a function rightrot(x,n) that returns the 
// value of the integer x rotated to the right by n positions.


unsigned rightrot(unsigned x, int n){
    int lengthOfWord(void);
    unsigned rbit;
    
    rbit = x << (lengthOfWord() - n);
    x = x >> n;
    x = x | rbit;
    
    return x;
}

int lengthOfWord(void)
{
    int i;
    unsigned v = (unsigned) ~0;

    for(i=1;(v=v>>1)>0;i++);
    return i;
}



// 30 points

// Write a function invert(x,p,n) that returns x with 
// the n bits that begin at position p inverted (i.e., 1 changed
// into 0 and vice versa), leaving the others unchanged.

//  XOR operator ^:  x ^  0  keeps x intact
// 				  :  x ^ ~0  equivalent to ~x  filps all bits of x

unsigned invert(unsigned x, int p, int n){
    int nn = ~(~0 << n); //flip the bits of x and then moves it bits n amounts of times to the left
    int pp = (p + 1 - n); 
    int ex = nn << pp; 
	return   x ^ ex ; 
}


// 60 points l

// Write a program to remove all comments from a proper C program.
// Don't forget to handle quoted strings and it's escape character properly. 


void remove_comments(){
	int c;
	while((c = getchar())!=EOF){
		char_removal(c);
	}
}


// EXTRA FUNCTIONS -------------------------------
// remove a character from a string
void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}


void char_removal(int c)
{
    int d;
    if( c == BACK_SLASH)
    {
        if((d=getchar())==ASTERISK_CHAR)
         incomment();
        else if( d == BACK_SLASH)
        {
            putchar(c);
            char_removal(d);
        }
        else 
        {
            putchar(c);
            putchar(d);
        }
    }
    else if( c == '\''|| c == QUOTE)
        check_quote(c);
    else
        putchar(c);
}

void incomment()
{
    int c,d;
     
    c = getchar();
    d = getchar();

    while(c!=ASTERISK_CHAR || d !=BACK_SLASH)
    {
        c =d;
        d = getchar();
    }
}

void check_quote(int c)
{
    int d;

    putchar(c);
    
    while((d=getchar())!=c)
    {
        putchar(d);
        
        if(d == (FORWARD_SLASH)){
			putchar(getchar());
		}
            
    }
    putchar(d);
}
