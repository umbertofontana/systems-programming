#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

	int array[10];
	int i;
	int * p = array; // p points to array

	// Assign to the array
	for (i=0;i<10;i++) {
		array[i] = 2*i; // Index times 2
	}

	// Index p at 5 and assign 1992
	p[5] = 1992;

	// Print the array
	for (i=0;i<10;i++) {
		printf("%d: %d\n", i, array[i]);
	}
}
