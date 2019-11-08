#include "syscall.h"

#define SIZE 100

/*
  pour lancer :
  ./userprog/nachos -x ./test/getstring
  comportement attendu :
  doit afficher une chaîne saisie (de taille 10 pour le test)
*/
int main(){
  char string[SIZE];
  
  GetString(string, SIZE);
  PutString(string);
  
  return 0;
}
