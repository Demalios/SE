#include "syscall.h"

void putchar_thread(void *c)
{
    PutChar((char)c);
    ThreadExit();
}


void putstring_thread(void *s)
{
    PutString((char *)s);
    ThreadExit();
}

int main()
{
    /*
    char *c = 't';
    ThreadCreate(putchar_thread, c);
    PutChar('r');
    */

    
    char s[] = "test";

    ThreadCreate(putstring_thread, s);
    PutString("autre");
    

    while(1);
    Halt();
}