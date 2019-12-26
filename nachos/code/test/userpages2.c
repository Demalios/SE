#include "syscall.h"

/*
  pour lancer :
  ./userprog/nachos -rs 1234 -x ./test/userpages2
  comportement attendu :
  affiche 12 fois le caractère 2

  *note : programme de test pour la partie II du TD3
*/

void putchar_thread(void *c)
{
    // cette convertion est utiliser pour éviter des "warnings" sur les types
    PutChar((char)(*(char *)c));
    ThreadExit();
}


int main()
{
    int i;
    for( i = 0; i<= 12 ; i++){
	    char c = '2';
	    ThreadCreate(putchar_thread, &c);
    }

    ThreadExit();
    Exit(0); // ce Exit() n'est pas atteint à cause du ThreadExit() juste avant
}
