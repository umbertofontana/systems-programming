#include <stdio.h>
#include <stdlib.h>

int main() {
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	int * p = array + 3;
	p[0] = 1992;

	for (int i=0; i<10; i++) {
		printf("%d ", array[i]);
		printf("\n");
	}
}
