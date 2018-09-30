#include <stdio.h>
#include <string.h>

int mystrlen( char * str){
  return *str? 1+mystrlen(++str):0;
}

char * mystrncpy(char * dest, char * orig, int n){
    int byteLimit = n;
    char * destp = dest;
    while(byteLimit-- && *orig) *(destp++) = *(orig++);
    return  dest;
}

int mystrcmp( char *s1, char *s2 ){
   while(*s1 && *s2){
     if (*s1 < *s2)return -1;
     else if(*s1++ > *s2++) return 1;
   }
   return 0;
}


int main(){

  char s1[10] = "hello";
  char * s2 = "world";
  printf("-------Testing strlen-------\n");
  printf("s1 mystrlen size: %d\n", mystrlen(s1));
  printf("s1 strlen size  : %d\n", strlen(s1));


  printf("-------Testing strcmp-------\n");
  printf("strcmp   : %d\n", strcmp(s1,s2));
  printf("strcmp   : %d\n", strcmp(s2,s1));
  printf("mystrcmp : %d\n", mystrcmp(s1 ,s2));
  printf("mystrcmp : %d\n", mystrcmp(s2,s1));

  printf("-------Testing strncpy-------\n");
  printf("mystrncpy(should be worlo) : %s\n", mystrncpy(s1, s2, 4));
  char s3[10] = "hello";
  printf("strncpy  (should be worlo) : %s\n", strncpy(s3, s2, 4));


  return 0;
}
