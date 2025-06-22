#include <stdio.h>
#include <stdlib.h>

struct pair{
	int left;
	int right;
};

int main(int argc, char * argv[]) {
	struct pair p;
	struct pair * q;

	q = &p;

	p.left = 20;
	p.right = 10;

	printf("p: (%d, %d)\n", p.left, p.right);
	printf("q: (%d, %d)\n", q->left, q->right);
}
