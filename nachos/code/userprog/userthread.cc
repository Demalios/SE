#ifdef CHANGED
#include <string.h>

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


static void StartUserFork(void *thread)
{
  Thread *t = (Thread *)thread;
  t->space->InitRegisters ();	// set the initial register values
  t->space->RestoreState ();	// load page table register
  machine->Run();
}


int do_ForkExec(const char *s)
{
    DEBUG ('s', "start ForkExec\n");
    OpenFile *executable = fileSystem->Open(s);
    
    if (executable == NULL)
      {
	  SetColor (stdout, ColorRed);
	  SetBold (stdout);
	  printf ("Unable to open file %s\n", s);
	  ClearColor (stdout);
	  return -1;
      }

    // thread create
    try
    {
        DEBUG ('s', "creating thread\n");
        Thread* newThread = new Thread("New Thread") ;

        newThread->space = new AddrSpace (executable);
	newThread->Start(StartUserFork, newThread);
        //newThread->space->InitRegisters ();	// set the initial register values
        //newThread->space->RestoreState ();	// load page table register
        DEBUG ('s', "thread created\n");

        delete executable;		// close file
        //machine->Run();
    }
    catch(int e)
    {
        DEBUG ('s', "Error in ForkExec().\n");
        delete executable;		// close file
        return -1;
    }

    return 1;
}


#endif // CHANGED
