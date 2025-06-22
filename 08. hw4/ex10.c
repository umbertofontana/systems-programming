#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[]){
char ** curarg;
int i=0;
int test;

 for( curarg=argv; *curarg ; curarg++){

   // Use sscanf() to perform a number/integer check

   if(sscanf(*curarg,"%d",&test) != 0) /*check passes*/

     printf("argv[%d] = %s (is a number!)\n", i++, *curarg);
   else
     printf("argv[%d] = %s (is *NOT* a number!)\n", i++, *curarg);
 }

}

