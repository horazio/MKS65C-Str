#include <stdio.h>
#include <string.h>
#include "str.h"

int mystrlen( char * str ){
  return * str? 1 + mystrlen(++str):0;
}

char * mystrncpy(char * dest, char * orig, int n){
  int byteCount = 0;
  while(byteCount < n){
    *(dest + byteCount) = *(orig + byteCount);
    byteCount++;
  }
  return dest;
}

char * mystrncat( char * dest, char * orig, int n){
  int byteCount = 0;
  int destLen = mystrlen(dest);
  while(byteCount++ < n){
    *(dest + byteCount + destLen) = *(orig + byteCount);
  }
  *(dest + byteCount + destLen) = 0;
  return dest;
}

char * mystrchr( char *s, char c ){
  while(*(s++)){
    if(*s == c){
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

void test(char * s1, char * s2, int i, char c){


  printf("-------Testing strlen-------\n");
  printf("s1 mystrlen size: %d\n", mystrlen(s1));
  printf("s1 strlen size  : %ld\n\n", strlen(s1));


  printf("-------Testing strchr-------\n");
  printf("strchr   : %p\n", strchr(s1, c));
  printf("mystrchr : %p\n\n", mystrchr(s1, c));


  printf("-------Testing strncat-------\n");
  printf("strncat   : %s\n", strncat(s1, s2, i));
  printf("mystrncat : %s\n\n", mystrncat(s1, s2, i));


  printf("-------Testing strcmp-------\n");
  printf("strcmp   : %d\n", strcmp(s1,s2));
  printf("strcmp   : %d\n", strcmp(s2,s1));
  printf("mystrcmp : %d\n", mystrcmp(s1 ,s2));
  printf("mystrcmp : %d\n\n", mystrcmp(s2,s1));

  printf("-------Testing strncpy-------\n");
  printf("mystrncpy : %s\n", mystrncpy(s1, s2, i));
  printf("strncpy   : %s\n", strncpy(s1, s2, i));

  printf("\n\n");
}


int main(){
  char s1[10] = "asdf";
  test(s1, "1234", 2, '4');

  char s2[10] = "te13st";
  test(s2, "12d4", 2, 'f');

  char s3[20] = "te23fst";
  test(s3, "1da4", 4, 'e');

  char s4[10] = "te";
  test(s4, "12dd4", 6, '4');

  return 0;
}
