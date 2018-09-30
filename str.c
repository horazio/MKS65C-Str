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
    if(*(s) == c){
      return s;
    }
  }
  return 0; 
}

int mystrcmp( char *s1, char *s2 ){
   while(*s1 && *s2){
     if (*s1 < *s2)return -1;
     else if(*s1++ > *s2++) return 1;
   }
   return 0;
}


int main(){
  char s1[10] = "qwe";
  char * s2 = "qwertyuiop";
  int i = 4;
  char c = '3';

  //printf("%s \n", strncpy(s1,s2,i));
  
  //printf("strlen says: %ld, mystrlen says: %d \n", strlen(s1), mystrlen(s1));
  //printf("strncpy says: %s, mystrncpy says: %s \n", strncpy(s1, s2, i), mystrncpy(s1, s2, i));
  //printf("strncat says: %s, mystrncat says: %s \n", strncat(s1, s2, i), mystrncat(s1, s2, i));
  //printf("strchr says: %p, mystrchr says: %p  \n", strchr(s2, c), mystrchr(s2, c));

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
