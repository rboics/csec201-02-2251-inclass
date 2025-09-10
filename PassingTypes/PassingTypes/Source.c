#include <stdio.h>

//Pass by reference
//Note: X is a pointer
void addTwo(int* x) {
	*x = *x + 2; //Note: the use of the dereference operator
				 //This modifies num, not a copy of num
	printf("Added Two: %d\n", *x);
}

//Pass by value
void addOne(int x) {
	x = x + 1; //Modifies a copy of num
	printf("Added One: %d\n", x);
}


int main(void) {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);	//Note the use of the reference operator (&)
	addOne(num);
	printf("The number you entered was: %d\n", num);
	addTwo(&num);		//Note the use of the reference operator
	printf("The number you entered was: %d\n", num);

	//which is better?
	//num = addTwo(num); - pass by value, modify value, return modified value
	//addTwo(&num); - pass by reference, modified the original
}