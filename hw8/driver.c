/*
 **
 * project: hw8
 * name: Jimmy Tran
 * user jimmyt16@users.cs.umb.edu
 * date: 5/5/2020
 * file: driver.c
 */


#include "hw8.h"



int main(int argc, char* argv[])
{
	Class * class = readClass(argv[1]);
	sortClass(class);
	freeClass(class);
	return 0;
}