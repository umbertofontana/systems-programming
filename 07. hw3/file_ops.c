#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

	FILE * gonavy = fopen("gonavy.txt", "w");
	FILE * beatarmy = fopen("beatarmy.txt", "w");
	fprintf(gonavy, "Go Navy\n");
	fprintf(beatarmy, "Beat Army\n");
	fclose(gonavy);
	fclose(beatarmy);

	fprintf(stderr, "Crash Airforce\n");
}
