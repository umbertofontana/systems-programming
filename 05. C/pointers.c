#include <stdio.h>

int main() {
	int a = 3;

	int * pointer_to_a = &a;

	printf("The value of a is %d\n", a);
	printf("The value of a is also %d\n", *pointer_to_a);
	printf("The memory address of a is %p\n", pointer_to_a);
	printf("The memory address of a is also %p\n", &a);
}
