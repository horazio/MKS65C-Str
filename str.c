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

char * mystrncat( char * dest, char * orig, int n){
  int c = 0;
  int l = mystrlen(dest);
  while(c++ < n){
    *(dest + c + l) = *(orig + c);
  }
  *(dest + c + l) = 0;
  return dest;
}

char * mystrchr( char *s, char c ){
  while(*(s++)){
    if(*(s) = c){
      reurn s;
    }
  }
  return 0; 
}

int main(){
  char s1[10] = "qwe";
  char * s2 = "qwertyuiop";
  int i = 4;
  char c = 'p'

  //printf("%s \n", strncpy(s1,s2,i));
  
  //printf("strlen says: %ld, mystrlen says: %d \n", strlen(s1), mystrlen(s1));
  //printf("strncpy says: %s, mystrncpy says: %s \n", strncpy(s1, s2, i), mystrncpy(s1, s2, i));
  //printf("strncat says: %s, mystrncat says: %s \n", strncat(s1, s2, i), mystrncat(s1, s2, i));
  printf("strchr says: %s, mystrchr says: %s \n", strncat(s2, i), mystrncat(s2, i));

  return 0;
}
