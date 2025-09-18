#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	unsigned int a = 0xdeadbeef; // Hex number that is stored in memory
	unsigned char * p = (unsigned char *) &a;

	int i;
	printf("0x");
	for(i=0;i<4;i++){
		printf("%02x", p[i]);
	}
	printf("\n");
}
