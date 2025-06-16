#include <stdio.h>
#include <string.h>

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

	strcpy(&Onion.str, "Hello World!");
	printf("%f\n", Onion.f);
}
