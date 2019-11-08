#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "synchconsole.h"
#include "synch.h"

static Semaphore* readAvail;
static Semaphore* writeDone;
static Semaphore* consoleControl;

static void ReadAvailHandler(void* arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void* arg) { (void) arg; writeDone->V(); }

SynchConsole::SynchConsole(const char* in, const char* out){
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    consoleControl = new Semaphore("console avail", 1);

    console = new Console (in, out, ReadAvailHandler, WriteDoneHandler, 0);
}
SynchConsole::~SynchConsole(){
    delete console;
    delete consoleControl;
    delete writeDone;
    delete readAvail;
}
void SynchConsole::SynchPutChar(int ch){
    consoleControl->P ();
    console->PutChar (ch);
    writeDone->P ();
    consoleControl->V ();
}
int SynchConsole::SynchGetChar(){
    consoleControl->P ();
    readAvail->P ();
    int ret = console->GetChar ();
    consoleControl->V ();
    return ret;
}
void SynchConsole::SynchPutString(const char s[]){
    //consoleControl->P ();
    int i = 0;

    while(s[i] != '\0'){
        console->PutChar (s[i]);
        writeDone->P ();
	    i++;
    }
    //consoleControl->V ();
}
void SynchConsole::SynchGetString(char* s, int n){
    //consoleControl->P ();
    char c;
    int i = 0;

    do{
	    c = (char) console->GetChar ();
        readAvail->P ();
	    s[i] = c;
	    i++;
    }while(i < n-2 && c != '\n' && c != '\0');
    
    if(c != '\0'){
	    s[i] = '\0';
    }
    //consoleControl->V ();
}
#endif // CHANGED
