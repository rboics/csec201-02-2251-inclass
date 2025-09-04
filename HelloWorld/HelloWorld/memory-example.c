#include <stdio.h>

int main(void) {

	int x = 1;
	char y = 'A';
	float z = 2.5;


	//printf("%d", x) ----> %d is a format specifier for printing the CONTENTS of an integer
	// %p ---> is used for printing a memory address
	// & ---> when this a unary operator in front of a variable
	//		  it can be read as "memory address of"

	printf("%p - %d\n", &x, x);
	printf("%p - %c\n", &y, y);
	printf("%p - %f\n", &z, z);

}