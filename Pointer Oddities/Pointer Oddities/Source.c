#include <stdio.h>


int main(void) {
	int x = 1234512345; //X is 4 bytes long
	char* p = (char*)&x;
	for (int i = 0; i < 4; i++) {
		printf("%c\n", p[i]);
	}
}


/*
int main(void) {
	int x = 5;			
	char c = 'A';
	int* p = (int*)&c;
	//first 3 (00 00 05) are from x
	// 41 is 'A' in hex, from c
	//00 00 05 41
	// 541 in hex should 1345 in decimal
	printf("%d\n", *p);

}
*/