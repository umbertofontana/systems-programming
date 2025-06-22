#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char s1[] = "I love IC221!";
	char s2[strlen(s1)];

	int i;
	for(i=0;i<strlen(s1);i++){
	s2[i]=s1[i];
	}
}
