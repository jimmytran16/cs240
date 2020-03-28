#ifndef HW4_H
#define HW4_H


// 30 points
// Write the function any(s1,s2) , which
// returns the first location in a string s1 where any
// character from the
// string s2 occurs, or -1 if s1 contains no characters
// from s2 . (The standard library function strpbrk does 
// the same job but  returns a pointer to the location.)

int any(char s1[], char s2[]);

// 30 points
// Write squeeze(s1,s2)
// that deletes each character in s1 that matches any character 
// in the string s2 .

void squeeze(char s1[], char s2[]);

// 30 points
// Write a function rightrot(x,n) that returns the 
// value of the integer x rotated to the right by n positions.


unsigned rightrot(unsigned x, int n);


// 30 points
// Write a function invert(x,p,n) that returns x with 
// the n bits that begin at position p inverted (i.e., 1 changed
// into 0 and vice versa), leaving the others unchanged.

//  XOR operator ^:  x ^  0  keeps x intact
// 				  :  x ^ ~0  equivalent to ~x  filps all bits of x

unsigned invert(unsigned x, int p, int n);


// 60 points

// Write a program to remove all comments from a proper C program.
// Don't forget to handle quoted strings and it's escape character properly. 
// And for this question, we only deal with comments syntax of "/*.. */"
// not double slash comments "//...."


void remove_comments();



#endif