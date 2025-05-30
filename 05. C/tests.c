#include <stdio.h>

typedef struct {
	char * name;
	int age;
} person;

void birthday(person *p);

void birthday(person *p) {
	p->age++;
	printf("%p",p);
	printf("%d", *p);
}

int main() {
	person john;
	john.name="John";
	john.age=27;
	birthday(&john);
}
