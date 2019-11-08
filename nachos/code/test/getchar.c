#include "syscall.h"


/*
  pour lancer :
  ./userprog/nachos -x ./test/getchar
  comportement attendu :
  quand on tape un caractère, celui-ci doit s'afficher à l'écran
  si on tape plus d'un caractère, le premier est affiché, les autres sont ignorés
*/
int main()
{
  char c = GetChar();

  PutChar(c);
  PutChar('\n');
  
  return 0;
}
