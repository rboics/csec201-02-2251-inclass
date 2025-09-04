#include <stdio.h>	//This is the standard input/output library
					//Gives us printf and scanf

#include <string.h> //C Library that provides string-adjacent functionality


//Main function of program - programs need a main
//int --> return type
//main --> function name
//void --> parameters (void means no parameters)

int main(void) {

	char name[10]; //Create a character array of size 10	(higher address)
	char last[10]; //Create a character array of size 10	(lower address)

	//printf --> output function
	//No assumptions about spacing or linebreaks
	// \n --> a newline
	printf("Enter your name: ");
	
	//scanf -> 1st arg is a format specifier that tells C how to handle data
	//2nd argument --> Memory address where the data is supposed to go
	scanf("%s", name);

	printf("Hello %s\n", name);

	printf("Enter your last name: ");
	scanf("%s", last);
	printf("Hello %s %s\n", name, last);
	printf("Goodbye!\n"); //Only exists to be a breakpoint



}
