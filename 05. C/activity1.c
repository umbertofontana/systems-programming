#include <stdio.h>

int main() {
	int s = 0;
	int a;

	printf("Enter numbers to sum: (enter q when done)\n");
	while (scanf("%d", &a) != 0) {
		s += a;
	} 
	printf("The sum is: %d\n", s);
}
