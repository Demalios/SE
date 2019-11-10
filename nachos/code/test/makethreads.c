#include "syscall.h"

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
