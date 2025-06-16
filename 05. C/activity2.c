#include <stdio.h>
#include <stdlib.h>

int main() {
	int s = 0;
	int a = 0;

	FILE * myfile = fopen("input.txt","r");
	while(fscanf(myfile, "%d", &a) != EOF) {
		s += a;
	}
	fclose(myfile);
	printf("The sum is: %d\n", s);

}
