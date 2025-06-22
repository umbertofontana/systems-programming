#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[] = "Beat Army\0Crash Airforce\0";

	printf("1: %s\n",s);
	printf("2: %s\n", s+17);
} 
