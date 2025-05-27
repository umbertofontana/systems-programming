#include <stdio.h>

int main() {
	char vowels[] = {'A','E','I','O','U'};
	char *pVowels = vowels;
	char *pVowels2 = &vowels;
	char *pVowels3 = &vowels[0];
	printf("%p, %p, %p\n", pVowels, pVowels2, pVowels3);
	int i;
	
	// Print the addresses
	for (i = 0; i < 5; i++) {
		printf("&vowels[%d]: %p, pVowels + %d: %p, vowels + %d: %p\n", i, &vowels[i], i, pVowels + i, i, vowels+i);
	}
	
	// Print the values
	for (i = 0; i < 5; i++) {
		printf("vowels[%d]: %c, *(pVowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pVowels + i), i, *(vowels + i));
	}
}
