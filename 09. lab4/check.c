#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_check(char * cc_str);
int valid_check(char * cc_str);

/* Input sanitization and check function */
int input_check(char * cc_str) {
	/* Second error condition: invalid length of credit card number */
	if (strlen(cc_str) != 16) {
		fprintf(stderr, "ERROR: Invalid credit card number: Bad Length\n");
		return 1;
	}
	/* Third error condition: not all numbers */
	for (int i=0; i<16; i++) {
		if (cc_str[i] < '0' || cc_str[i] > '9') {
		fprintf(stderr, "ERROR: Invalid credit card number: Bad number '%c'\n",cc_str[i]);
		return 1;
		}
	}
	return 0;
}

/* Check for valid or invalid credit card number using Luhn's Algorithm */
int valid_check(char * cc_str) {
	int checksum;
	/* Convert credit card string to array of integers */
	/* Array to store credit card number as array of integers*/
	int cc_num[16];
	/* Array to isolate each character in order to use atoi() on it */
	char num[2];
	num[1] = '\0'; // NULL terminate each isolated character
	/* Convert from string to int and store in new array */ 
	for (int i=0; i<16; i++) {
		num[0] = cc_str[i];
		cc_num[i] = atoi(num);
	}
	/* Check with Luhn's Algorithm */
	/* Double every other digit starting with the first */
	for (int i=0; i<16; i+=2) {
		cc_num[i] = cc_num[i]*2;
		/* If the double of a digit is greater than 9, replace it with the sum of its two digits */
		if (cc_num[i]>9) {
			/* Cool approach using the remainders of division by 10 */
			int rem, sum = 0;
			int num = cc_num[i];
			while (num != 0) {
				rem = num % 10;
				sum = sum + rem;
				num = num / 10;
    			}
			cc_num[i] = sum;
		}
	}
	/* Take the checksum of all the remainders */
	for (int i=0;i<16;i++) {
		checksum += cc_num[i];
	}
	/* Check that the sum of all the remainders is a multiple of 10 */
	if (checksum % 10==0) {
		printf("VALID\n");
		return 0;
	} else {
		printf("INVALID\n");
		return 1;
	}
}

int main(int argc, char * argv[]){
  
	/* First error condition: no argument provided */
	if (argc == 1) {
		fprintf(stderr, "ERROR: require credit card number\n");
		return 1;
	}

	if (input_check(argv[1])==0) {
		/* Input check passed */
		if (valid_check(argv[1])==0) {
			/* Valid number check passed */
			return 0;
		} else {
			/* Valid number check failed */
			return 2;
		} }
	else {
		/* Input check failed */
		return 1;
	}
}
