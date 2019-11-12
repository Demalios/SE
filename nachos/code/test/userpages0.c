#include "syscall.h"

/*
  pour lancer :
  ./userprog/nachos -x ./test/userpages0
  comportement attendu :
  afficher quelques caractères

  *note : programme de test pour la partie I du TD3
*/

int main()
{
    PutString("quelques caractères.\n");

    Exit(0);
}