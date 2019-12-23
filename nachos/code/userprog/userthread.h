#ifdef CHANGED
/* userthread.h 
 * 	
 */

#ifndef DEF_USERTHREAD
#define DEF_USERTHREAD

#include "machine.h"
#include "system.h"
#include "addrspace.h"

typedef struct
{
    int func;
    int args;

}Params;


/**
 * Create a new thread, initialize it and put it in the excecution queue
 * > f : adress of the function used to create the thread
 * >  arg : adress of the arguments of the function
 * return : adress of the thread created
**/
extern int do_ThreadCreate(int f, int arg);


/**
 * Destroy the active thread
 * return : none
**/
extern void do_ThreadExit(void);


/**
 * Create a new main thread, initialize it and put it in the excecution queue
 * > s : path to an executable
 * return : 1 if it works, else -1
**/
extern int do_ForkExec(const char *s);

 #endif

 #endif // CHANGED