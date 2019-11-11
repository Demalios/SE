#include "syscall.h"

/*
  pour lancer :
  ./userprog/nachos -rs 1234 -x ./test/makethread
  comportement attendu :
  > '1' et '2' doivent s'afficher à un moment dans la console
  > "autre" et "test" doivent s'afficher à un moment dans la console
  > 6 'a' doivent s'afficher entre les autres mots ou caractères affichés comme décrit précédemment (pour les mots, 'a' ne doit pas s'afficher entre les caracteres qui les composent)
*/

void putchar_thread(void *c)
{
    // cette convertion est utiliser pour éviter des "warnings" sur les types
    PutChar((char)(*(char *)c));
    ThreadExit();
}


void putstring_thread(void *s)
{
  volatile int i = 0;
  
  for(i = 0; i < 6; i++)
    {
      PutChar('a');
    }
  PutChar('\n');
  PutString(s);
  ThreadExit();
}


int main()
{
    char c = '2';
    int i = 0;
    ThreadCreate(putchar_thread, &c);
    PutChar('1');
  
    ThreadCreate(putstring_thread, "test\n");
    PutString("autre\n");
    
    // cette boucle d'attente est commentée pour justifier les tests fais en partie 1...
    //while(1);

    // ... même chose pour le halt
    //Halt();
    
    ThreadExit();
    Exit(0); // ce Exit() n'est pas atteint à cause du ThreadExit() juste avant
}
