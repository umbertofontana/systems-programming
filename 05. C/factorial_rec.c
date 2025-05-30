#include <stdio.h>

/* Declaring the function */
int factorial(int x);

int main() {
    /* Testing code */
    printf("0! = %i\n", factorial(0));
    printf("1! = %i\n", factorial(1));
    printf("3! = %i\n", factorial(3));
    printf("5! = %i\n", factorial(5));
}

/* Define your function here */
/* Declaring the function */
int factorial(int x) {
	if (x == 0) {
		return 1;
	}
	else if (x >= 1) {
		return factorial(x-1) * x;
	}
}
