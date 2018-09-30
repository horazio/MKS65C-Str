#include <stdio.h>
#include <string.h>
#include "str.h"

int mystrlen( char * str ){
  return * str? 1 + mystrlen(++str):0;
}

char * mystrncpy(char * dest, char * orig, int n){
  int c = 0;
  while(c++ < n){
    *(dest + c) = *(orig + c);
  }
  return dest;
}



int main(){
  char s1[10] = "df";
  char * s2 = "wofasdfasdfasdfasdfasdfasdfasdfasdfo";
  int i = 20;

  printf("%s \n", strncpy(s1,s2,i));
  
  // printf("strlen says: %ld, mystrlen says: %d \n", strlen(s1), mystrlen(s1));
  //printf("strncpy says: %s, mystrncpy says: %s \n", strncpy(s1, s2, i), mystrncpy(s1, s2, i));
  
  return 0;
}
