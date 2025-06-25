#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check1(char * str);
int check2(char * str1);

/* Iterating front-to-back and back-to-front to check for a palindrome */
int check1(char *str){
	for(int i=0; i<strlen(str); i++) {
		if(str[i]!=str[strlen(str)-i-1]){
			return 0;
		}
	}
	return 1;
}

/* Copy str1 to str2 backwards and comparing the two strings with strcmp() */
int check2(char *str1){
	char str2[1024];
	for (int i=0; i<strlen(str1); i++) {
		str2[i] = str1[strlen(str1)-i-1];
	}
	str2[strlen(str1)] = 0; // NULL-terminate str2 in order for strcmp() to work properly
	if(strcmp(str1, str2) == 0) {
		return 1;
	}
	else{
		return 0;
	}
}

int main(int argc, char * argv[]){

  char str[1024];

  printf("Enter a string:\n");

  scanf("%1023s",str);

  if(check1(str)){ // This is TRUE if any non-zero value is returned, FALSE if 0 is returned
    printf("Palindrome according to check 1\n");
  }else{
    printf("NOT a palindrome according to check 1\n");
  }
   

  if(check2(str)){
    printf("Palindrome according to check 2\n");
  }else{
    printf("NOT a palindrome according to check 2\n");
  }
  
}
