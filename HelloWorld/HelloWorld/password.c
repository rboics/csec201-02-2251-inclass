//Example from hacking: the art of exploitation

#include <stdio.h>
#include <string.h>


int main(void) {
	int flag = 0;
	char password[10];

	printf("Enter the password: ");
	scanf("%s", password); //Equivalent to: &(password[0])
	
	//If the user enter "friend", set flag to 1
	if (strcmp(password, "friend") == 0) {
		flag = 1;
	}

	if (flag != 0) {
		printf("Password accepted!\n");
	}
	else {
		printf("Password rejected\n");
	}

}