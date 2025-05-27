#include <stdio.h>

char dest1[20] = "Hello";
char dest2[20] = "Hello";
char src[20] = "World";
int a = 3;
int b = 20;
strncat(dest1,src,a);
printf("%s\n",dest1);
strncat(dest2,src,b);
printf("%s\n",dest2);
