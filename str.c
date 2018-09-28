#include <stdio.h>
#include <string.h>
#include "str.h"

int mystrlen( char * str ){
  return * str? 1 + mystrlen(++str):0;
}

char * mystrncpy(char * dest, char * orig, int n){
  char * p = orig;
  char * p2 = dest;
  while(p - orig - n){
    *(p2++) = *(p++);
  }
  return dest;
}



int main(){
  char s1[10] = "";
  char * s2 = "wo";
  int i = 30;
  
  printf("strlen says: %ld, mystrlen says: %d \n", strlen(s1), mystrlen(s1));
  //printf("strncpy says: %s, mystrncpy says: %s \n", strncpy(s1, s2, i), mystrncpy(s1, s2, i));
  
  return 0;
}
