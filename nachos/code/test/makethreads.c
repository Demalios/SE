#include "syscall.h"

/*
  pour lancer :
  ./userprog/nachos -rs 1234 -x ./test/makethread
  comportement attendu :
  si les premières lignes du main sont décommentées 'r' et 't' doivent s'afficher
  si les dernières lignes du main sont décommentées "autre" et "test" doivent s'afficher
*/

void putchar_thread(char c)
{
    PutChar(c);
    ThreadExit();
}


void putstring_thread(char *s)
{
    PutString(s);
    ThreadExit();
}

int main()
{
    /*
    ThreadCreate(putchar_thread, 't');
    PutChar('r');
    */
  
    ThreadCreate(putstring_thread, "test");
    PutString("autre");

    while(1);
    Halt();
}
