#include "syscall.h"

/*
  pour lancer :
  ./userprog/nachos -x ./test/putchar
  comportement attendu :
  doit afficher "abcd" (affichés caractère par caractère)
*/
void print(char c, int n)
{
  int i;
#if 1
  for (i = 0; i < n; i++)
    {
      PutChar(c + i);
    }

  PutChar('\n');
#endif
}

int main()
{
  print('a',4);
  while(1);
  Halt();
}
