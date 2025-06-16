#include <stdio.h>

int main()
{
	int intarray[5] = {10,20,30,40,50};
	int i;
	for(i = 0; i < 5; i++) {
		printf("The value of intarray[%d] is %d - and its address is @ %x\n", i, intarray[i], &intarray[i]);
	}

	int *intpointer = &intarray[3]; // Point to the 4th element in the array
	printf("Address: %x - has value %d\n", intpointer, *intpointer); // Print the address of the 4th element

	intpointer++; // Now increase the pointer's address so it points to the 5th elemnt in the array
	printf("Address: %x - has value %d\n", intpointer, *intpointer); // Print the address of the 5th element

	return 0;
}
