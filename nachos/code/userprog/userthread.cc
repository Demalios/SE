#ifdef CHANGED
#include "userthread.h"
#include "system.h"
#include "syscall.h"

/**
 * Initialize registeries and run the thread
 * > schmurtz : a pointer toward a structure containing the function and arguments addresses
 * return : none
**/
static void StartUserThread(void *schmurtz)
{
    DEBUG ('x', "Begin startUserThread\n");
    Params *p = (Params *)schmurtz;

    machine->WriteRegister (4, p->args);
    machine->WriteRegister (PCReg, p->func);
    machine->WriteRegister (NextPCReg, p->func + 4);

    machine->WriteRegister (StackReg, currentThread->space->AllocateUserStack());
    DEBUG ('x', "Initializing stack register to 0x%x\n",currentThread->space);

    nbThreads += 1;
    
    machine->Run();
}


int do_ThreadCreate(int f, int arg)
{
    try
    {
        DEBUG ('x', "creating thread\n");
        Thread* newThread = new Thread("New Thread") ;

        Params* p = new Params();

        p->func = f;
        p->args = arg;

        newThread->space = currentThread->space;
        newThread->Start(StartUserThread, p);
        DEBUG ('x', "thread created\n");
    }

    catch(int e)
    {
        DEBUG ('x', "Error in do_ThreadCreate().\n");
        return -1;
    }
    
    return 1;
}


void do_ThreadExit(void)
{
    if(nbThreads > 1)
      {
	nbThreads -= 1;
	currentThread->Finish();
      }
    else
      {
	interrupt->Halt ();
      }
}

#endif // CHANGED
