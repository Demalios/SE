#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "synchconsole.h"
#include "synch.h"

static Semaphore* readAvail;
static Semaphore* writeDone;

static Semaphore* consolePutString;
static Semaphore* consoleGetString;
static Semaphore* consolePutChar;
static Semaphore* consoleGetChar;

static void ReadAvailHandler(void* arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void* arg) { (void) arg; writeDone->V(); }

SynchConsole::SynchConsole(const char* in, const char* out){
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    consolePutString = new Semaphore("put string avail", 1);
    consoleGetString = new Semaphore("get string avail", 1);
    consolePutChar = new Semaphore("put char avail", 1);
    consoleGetChar = new Semaphore("get char avail", 1);

    console = new Console (in, out, ReadAvailHandler, WriteDoneHandler, 0);
}
SynchConsole::~SynchConsole(){
    delete console;

    delete consoleGetChar;
    delete consolePutChar;
    delete consoleGetString;
    delete consolePutString;
    delete writeDone;
    delete readAvail;
}
void SynchConsole::SynchPutChar(int ch){
    consolePutChar->P ();
    console->PutChar (ch);
    writeDone->P ();
    consolePutChar->V ();
}
int SynchConsole::SynchGetChar(){
    consoleGetChar->P ();
    readAvail->P ();
    int ret = console->GetChar ();
    consoleGetChar->V ();
    return ret;
}
void SynchConsole::SynchPutString(const char s[]){
    consolePutString->P ();
    int i = 0;

    while(s[i] != '\0'){
        SynchPutChar (s[i]);
	    i++;
    }
    consolePutString->V ();
}
void SynchConsole::SynchGetString(char* s, int n){
    consoleGetString->P ();
    char c;
    int i = 0;

    do{
	    c = (char) SynchGetChar ();
	    s[i] = c;
	    i++;
    }while(i < n-2 && c != '\n' && c != '\0');
    
    if(c != '\0'){
	    s[i] = '\0';
    }
    consoleGetString->V ();
}
#endif // CHANGED
