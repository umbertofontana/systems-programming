#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int * a; // Array of ints
	int size; // Of this size
} mytype_t;

mytype_t ** allocate(int n){
	mytype_t ** mytypes;
	int i,j;

	mytypes = calloc(n, sizeof(mytype_t *));
	
	for(i=0;i<n;i++) {
		mytypes[i] = malloc(sizeof(mytype_t));

		mytypes[i]->a = calloc(i+1,sizeof(int));

		for(j=0;j<i+1;j++){
			mytypes[i]->a[j] = j*10;
		}

		mytypes[i]->size = i;
	}
	return mytypes;
}

void dealloc(int n, mytype_t ** items) {
	int i,j;

	for(i=0;i<n;i++){
		free(items[i]->a);
		free(items[i]);
	}

	free(items);
}

int main(){
	int i;
	mytype_t ** mytypes;

	mytypes = allocate(10);

	for(i=0;i<10;i++){
		printf("mytypes[%d] = [", i);
		for(j=0;j<mytypes[i]->size;j++){
			printf(" %d", mytypes[i]->a[j]);
		}
		printf(" ]\n");
	}
	dealloc(10, mytypes);
}
