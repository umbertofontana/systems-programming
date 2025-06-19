#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	char a[] = {'G', 'o', ' ', 'N', 'a', 'v', 'y', '!'}; // Forgot the NULL terminator
	char b[] = {'G', 'o', ' ', 'N', 'a', 'v', 'y', '!', '\0'};

	printf("a: %s\n", a);
	printf("b: %s\n", b);
}
