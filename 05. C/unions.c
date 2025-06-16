#include <stdio.h>

struct my_struct {
	int x;
	float f;
	char str[16];
};

union my_onion {
	int x;
	float f;
	char str[16];
};

int main() {
	union my_onion Onion;
	struct my_struct Strooct;

	printf("Union: %d\n", sizeof(Onion));
	printf("Struct: %d\n", sizeof(Strooct));
}
