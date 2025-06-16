#include <stdio.h>
#include <stdlib.h>

/* Prints out the array in a single line.
 * Remember that it's customary to pass both the reference 
 * to the array and the size of it to the function */
void print_array(int * array, int len){
  printf("{ ");
  for (int i=0; i<len; i++) {
	  printf("%d ", array[i]);
  }
  printf("} \n");
}

/* Reverse the array and print it out using the print_array function */
void reverse_array(int * array, int len){
	int swap;
	for (int i = 0; i<(len/2); i++) {
		swap = array[i];
		array[i] = array[len-1-i];
		array[len-1-i] = swap;
	}
	print_array(array, len);
}

/* Randomize the array using the random() function and print it with the print_array function */
void randomize_array(int * array, int len){
	int r; // Variable to store the random number
	int swap; // Temp variable to store swapping values
	for (int i=0; i<len;i++) {
		r = random() % len; // Produce a random number between 0 and len-1
		swap = array[i]; // Same swapping as in the reverse_array function
		array[i] = array[r];
		array[r] = swap;	
	}	
	print_array(array, len);
}

/* Sort the array using insertion sort and print it with the print_array function */
void sort_array(int * array,int len){
	int swap;
	/* Check if the second element of the array is less than the first. If it is, 
	 * swap them. If it's not, go on to the third element, and check if it's
	 * less then the first or the second. Go on like this and you get a sorted array. */
	for (int i=1;i<len;i++) { // Start from 1 because we start from the second element
		for (int j=0;j<i-1;j++) { // This is the iteration where we compare the i-th 
					  // element to the j-th elements up to it (i-1).
			if (array[i] < array[j]) {
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;	
			}

		}
	}
	print_array(array, len);
}

int main(int argc, char *argv[]){

  int len=0;    // Store the length of the array, initially 0 but will change
  int res;      // Store the result of scanf() operations
  int choice;   // Store the user choice for operations
  int i;        // An interator for loops

  srandom(1992);//seed random number generator

  printf("Enter the length:\n");

  // Request the length of the array. 
  res = scanf("%d", &len);
  if (res == 0) {
	  printf("ERROR: Invalid input\n");
	  return 1;
  }

  int array[len]; // Declare array now that we know its size


  printf("Enter %d numbers (space separated):\n",len);

  //  Read in desired numbers

  for (i=0; i<len; i++) {
	res = scanf("%d", &array[i]);
	if (res == 0) {
		printf("ERROR: Invalid input\n");
		return 1;
	}
  }


  // While loop for operations, run until exit or EOF
  while(1){
    printf("Choose an operation:\n");
    printf("(0) : exit\n");
    printf("(1) : print array\n");
    printf("(2) : reverse array\n");
    printf("(3) : randomize array\n");
    printf("(4) : sort array\n");
    res = scanf("%d",&choice);

    // Error check
    if(res == 0){
      char c;
      printf("ERROR: Invalid input. Choose again.\n");

      scanf("%c",&c);// Clear stdin and continue
      continue;
    }else if(res == EOF){
      break;
    }

    // Function calls based on user choice

    if (choice == 0){
      break;
    } else if (choice == 1) {
    	print_array(array, len);	
    } else if (choice == 2) {
    	reverse_array(array, len);
    } else if (choice == 3) {
	randomize_array(array, len);
    } else if (choice == 4) {
    	sort_array(array, len);
    }
    else {
      printf("ERROR: Invalid number. Choose again.\n\n");
      continue;
    }
    
  }
  return 0; //return 0 on success

}
