#include "syscall.h"

int main()
{
    PutString("test de putString.\n");
    PutString("test numéro : 2.\n");
    PutString("autre test !\n");
    PutString("Fin des tests, si on arrive ici on peut considérer que ça fonctionne plutôt bien...\n");
    Halt();
}