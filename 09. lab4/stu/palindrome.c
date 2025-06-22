#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check1(char * str);
int check2(char * str1);

int check1(char *str){
  //TODO: Complete by iterating from front-to-back and back-to-front
  //      to check for a palindrome
}

int check2(char *str1){
  char str2[1024]; //string to copy to

  //TODO: Complete by copying str1 to str2, backwards, and then
  //      checking that str1 and str2 are the equal using strcmp()


}

int main(int argc, char * argv[]){

  char str[1024];

  printf("Enter a string:\n");

  scanf("%1023s",str);

  if(check1(str)){
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
