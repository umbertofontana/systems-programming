#include <stdio.h>

typedef union {
	unsigned int addr;
	unsigned char bytes[4];
} ipv4_addr;

int main() {
	ipv4_addr myaddr = {0};

	myaddr.bytes[0] = 127;
	myaddr.bytes[1] = 0;
	myaddr.bytes[2] = 0;
	myaddr.bytes[3] = 1;

	printf("%x\n", myaddr.addr);
}
