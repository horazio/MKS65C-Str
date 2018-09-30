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
  while(byteCount < n){
    *(dest + byteCount + destLen) = *(orig + byteCount);
    byteCount++;
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

char * mystrstr( char *s1, char * s2 ){
  char * s1p;
  char * s2p;
  while(*s1){
    s1p = s1++;
    s2p = s2;
    while(*s1p == *s2p && *s2p ){
      s1p++;
      s2p++;
    }
    if (!(*s2p))return (s1 - 1);
  }
  return 0;
}

void test(char * s1, char * s2, int i, char c, char * s3, char *s4, char *s5){

  printf("################## NEW TEST ####################\n\n\n");
  printf("-------Testing strlen-------\n");
  printf("[OURS]      : %d\n", mystrlen(s1));
  printf("[STANDARD]  : %ld\n\n", strlen(s1));
  printf("[OURS]      : %d\n", mystrlen(s2));
  printf("[STANDARD]  : %ld\n\n", strlen(s2));


  printf("-------Testing strchr-------\n");
  printf("[OURS]      : %p\n\n", mystrchr(s3, c));
  printf("[STANDARD]  : %p\n", strchr(s3, c));


  printf("-------Testing strncat-------\n");
  printf("[OURS]      : %s\n", mystrncat(s5, s2, i));
  printf("[STANDARD]  : %s\n", strncat(s1, s2, i));


  printf("-------Testing strcmp-------\n");
  printf("[OURS]      : %d\n", mystrcmp(s1 ,s2));
  printf("[OURS]      : %d\n\n", mystrcmp(s2,s1));
  printf("[STANDARD]  : %d\n", strcmp(s1,s2));
  printf("[STANDARD]  : %d\n", strcmp(s2,s1));


  printf("-------Testing strncpy-------\n");
  printf("[OURS]      : %s\n", mystrncpy(s1, s2, i));
  printf("[STANDARD]  : %s\n", strncpy(s1, s2, i));


  printf("-------Testing strstr-------\n");
  printf("[OURS]      : %s\n", mystrstr(s3, s4));
  printf("[STANDARD]  : %s\n", strstr(s3, s4));

  printf("\n\n");
}


int main(){
  char s1[10] = "asdf";
  char t1[10] = "asdf";  //needed for simultaneous testing of strncat
  test(s1, "1234", 2, 'a', "sdaldfj" , "ald", t1);

  char s2[10] = "te13st";
  char t2[10] = "te13st";//needed for simultaneous testing of strncat
  test(s2, "12d4", 2, 'f', "13dfad", "3d", t2);

  char s3[20] = "te23fst";
  char t3[20] = "te23fst";//needed for simultaneous testing of strncat
  test(s3, "1da4", 4, 'w', "e23f", "adfadf",t3);

  char s4[10] = "tesadf";
  char t4[10] = "tesadf";//needed for simultaneous testing of strncat
  test(s4, "12dd4", 6, 's', "esaadfa", "a",t4);

  return 0;
}
