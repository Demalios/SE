#include "syscall.h"

/*
  pour lancer :
  ./userprog/nachos -x ./test/putstring
  comportement attendu :
  4 chaînes de caractères (avec retour à la ligne) doivent s'écrire dans la console
*/
int main()
{
    PutString("test de putString.\n");
    PutString("test numéro : 2.\n");
    PutString("autre test !\n");
    PutString("Fin des tests, si on arrive ici on peut considérer que ça fonctionne plutôt bien...\n");
    Halt();
}
