#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int a[] = {1, 2, 3};
	int b[10] = {1, 2, 3};
	int i;
	
	printf("sizeof(a):%d sizeof(b):%d\n", (int) sizeof(a), (int) sizeof(b));
	printf("\n");
	for (i=0;i<3;i++) {
		printf("a[%d]: %d\n", i, a[i]);
	}
	printf("\n");
	for (i=0;i<10;i++) {
		printf("b[%d]: %d\n", i, b[i]);
	}
}
