#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	char str1[] = "This is a string";
	char * str2 = "This is also a string";
	str2 = str1;
	str2[3] = 'A';

	printf("str1: %s - &str1:%p\n", str1, str1);
	printf("str2: %s - &str2:%p\n", str2, str2);
}
