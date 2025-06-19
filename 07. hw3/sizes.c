#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Size of an int: %d\nSize of a char: %d\nSize of an int *: %d\nSize of a float *: %d\nSize of a char *: %d\nSize of a short: %d\nSize of an int **: %d\nSize of a float: %d\nSize of a double: %d\n", sizeof(int), sizeof(char), sizeof(int *), sizeof(float *), sizeof(char *), sizeof(short), sizeof(int **), sizeof(float), sizeof(double));
}

