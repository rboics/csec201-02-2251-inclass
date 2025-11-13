#include <stdio.h>

int main(void) {
	int x = 0;
	int y = 5;
	int z = 10;

	printf("%p %p %p\n", &x, &y, &z);

	printf("Doesn't matter; used for a breakpoint\n");
	x = x + 1; //move x into a register, add 1 to the register, move contents of register back into x
	y = y + 2;
	z = x + y;
	printf("Doesn't matter; used for a breakpoint\n");


}