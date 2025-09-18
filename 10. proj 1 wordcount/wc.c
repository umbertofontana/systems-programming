#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* 
 * IC221: Systems Programming Project 1: The Word Count Program
 * Developed by Umberto Fontana 
 * Usage: ./wc [-c -l -w] [file1] [file2] ...
 *
 * This program, similarly to the command line "wc" utility, counts the number of characters, words 
 * and lines in a file. The first number is the number of lines, the second number is the number of 
 * words, the third number the number of characters. If multiple files are specified, the totals in 
 * each category are also reported, after the individual file results. 
 *
 * If no files are specified, wc fill read from STDIN. A user can also indicate that they wish to 
 * read from STDIN using the "+" symbol as a file name. 
 *
 * Prior to the list of files, optional command line arguments can be provided to limit the output 
 * to just reporting the number of lines, number of words, or number of characters
 * (or some combination):
 * -l print number of lines
 * -w print number of words
 * -c print number of characters
 * All command line options must precede all filenames. Command line options must be separated: 
 * instead of -wlc, use -w -l -c
*/

// The fgetc function reads a character and returns an unsigned int. That unsigned int must be 
// fed to the isspace function in order to determine if it's a space.
// Use this logic to count characters first.

// I want the counter function to take the input stream of characters and return a pointer to an 
// array; this array will contain the three counted values of chars, lines and words

int counter(FILE * stream, int * counts);
int printer(int * counts, char * name, int * flags);

int main(int argc, char * argv[]) {
	int counts[] = {0, 0, 0}; // Array to store the values
	int flags[] = {0, 0, 0, 1}; // Array to store selected flags (-l, -w, -c, no flag selected) 
	int optcounter = 0; // Counter for the number of selected options
	int filecounter = 0; // Counter for the number of files
	int totc = 0; // Total number of characters
	int totl= 0; // Total number of lines
	int totw = 0; // Total number of words
	FILE * stream;

	// Read arguments one by one.
	
	for (int i=1; i<argc; i++) {
	// Evaluate command line options
					  
	// Evaluate if it starts with "-"
		if (argv[i][0] == '-') {
		// If it does, evaluate selected options
			if (strcmp(argv[i],"-l") == 0) {
				flags[0] = 1;
				flags[3] = 0;
				optcounter += 1;
			} else if (strcmp(argv[i],"-w") == 0) {
				flags[1] = 1;
				flags[3] = 0;
				optcounter += 1;
			} else if (strcmp(argv[i],"-c") == 0) {
				flags[2] = 1;
				flags[3] = 0;
				optcounter += 1;
			} else {
			// Invalid option selected: exit with status code 2
				fprintf(stderr, "ERROR: unknown option '%s'\n", argv[i]);
				return 2;
			}
		}
		else {
			// Break the loop once the program finds the first argv without a trailing "-"
			// All other args will be evaluated from now on as file names, even if they have a trailing "-"
			break;
		}
	}
	// Now that we have the number of options specified, we can start evaluating the user input from that point on, ignoring the options part
	
	// No file specified: read from STDIN
	if (argc == optcounter + 1) {
		counter(stdin, counts);
		printer(counts, "-STDIN-", flags);
	}
	// At least one file specified
	else {
		for (int i=optcounter+1; i<argc; i++) {
			// If the filename is a "+" read from STDIN and update the file counter
			if (strcmp(argv[i],"+") == 0) {
				counter(stdin, counts);
				printer(counts, "-STDIN-", flags);
				filecounter += 1;
				totl += counts[0];
				totw += counts[1];
				totc += counts[2];
			}
			// Else get the specified file and call counter, then update the file counter
			else {
				// Error handling for non-existent files, report and keep going
				if ((stream = fopen(argv[i], "r")) == NULL) {
					fprintf(stderr, "ERROR: file '%s' cannot be opened\n", argv[i]);
				} else {
					counter(stream, counts);
					filecounter += 1;
					fclose(stream);
					printer(counts, argv[i], flags);
					totl += counts[0];
					totw += counts[1];
					totc += counts[2];
				}
			}
		}
		if (filecounter > 1) {
			printf("total %d %d %d\n", totl, totw, totc);
		}
		
	}
	// End of main
	return 0;
}

int counter(FILE * stream, int * counts) {
	int curr = 0; // Current character
	int prev = 0; // Previous character
	int charcount = 0; // Character counter
	int linecount = 0; // Line counter
	int wordcount = 0; // Word counter
	// First iteration. Is character && NOT EOF -> First word. 
	if (curr = fgetc(stream) != EOF && isspace(curr)==0) {
		wordcount += 1;
		charcount += 1;
	}	
	while ((curr = fgetc(stream)) != EOF) {
		charcount+=1;
		if (curr == '\n') {
			linecount+=1;
		}
		// Current is character
		if (isspace(curr)==0) {
			if (isspace(prev)) {
		// Previous is whitespace, new word started, update counter
				wordcount += 1;
			}
		}
	// Update the prev character
	prev = curr;
	}
	// Store the values in an array as follows: [Lines,Words,Character]
	counts[0] = linecount;
	counts[1] = wordcount;
	counts[2] = charcount;
	
}

int printer(int * counts, char * name, int * flags) {
	// Flag evaluation, format accordingly and print
	// All flags selected
	if (flags[3] == 1) {
		printf("%s %d %d %d\n", name, counts[0], counts[1], counts[2]);
	} // Evaluate serially other possible options
	else {
		printf("%s ", name);
		
		if (flags[0] == 1) {
			printf("%d ", counts[0]);
		}
		if (flags[1] == 1) {
			printf("%d ", counts[1]);
		}
		if (flags[2] == 1) {
			printf("%d ", counts[2]);
		}
		printf("\n");
	}
}
