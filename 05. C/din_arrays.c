#include <stdio.h>
#include <stdlib.h>

int main() {
	int nrows = 2;
	int ncols = 5;
	int i, j;

	// Allocate memory for nrwos pointers
	char **pVowels = (char **)malloc(nrows * sizeof(char*));

	//For each row, allocate memory for ncols elements
	pVowels[0] = (char *)malloc(ncols * sizeof(char));
	pVowels[1] = (char *)malloc(ncols * sizeof(char));

	pVowels[0][0] = 'A';
	pVowels[0][1] = 'E';
	pVowels[0][2] = 'I';
	// [...]
	pVowels[1][0] = 'a';
	pVowels[1][1] = 'e';
	pVowels[1][2] = 'i';
	// [...]

	for (i = 0; i < nrows; i++) {
		for(j = 0; j < ncols; j++) {
			printf("%c ", pVowels[i][j]);
		}
		printf("\n");
	}

	// Free individual rows
	free(pVowels[0]);
	free(pVowels[1]);

	// Free the top-level pointer
	free(pVowels);
}
