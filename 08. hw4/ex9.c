#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  char ** curarg;
  int i=0;

  for( curarg=argv; *curarg ; curarg++){
    printf("argv[%d] = %s\n", i++, *curarg);
  }

}

