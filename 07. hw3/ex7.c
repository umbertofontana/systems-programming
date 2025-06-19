#include <stdio.h>
#include <stdlib.h>

int main() {

	int a=0, b=0, *p;

	p = &b; 
	printf("MARK 0: p:%p\n", p);

	*p = 15;
	printf("MARK 1: *p:%d b:%d\n", *p, b);

	a = b;
	b = 25;
	printf("MARK 2: a:%d b:%d\n", a, b);

	p = &a;
	printf("MARK 3: p:%p &a:%p\n", p, &a);

	(*p)++;
	printf("MARK 4: *p:%d a:%d\n", *p, a);
}
