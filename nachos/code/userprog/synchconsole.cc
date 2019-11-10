#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "synchconsole.h"
#include "synch.h"

static Semaphore* readAvail;
static Semaphore* writeDone;

static Semaphore* consoleString;
static Semaphore* consoleChar;

static void ReadAvailHandler(void* arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void* arg) { (void) arg; writeDone->V(); }

SynchConsole::SynchConsole(const char* in, const char* out){
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    consoleString = new Semaphore("console string avail", 1);
    consoleChar = new Semaphore("console char avail", 1);

    console = new Console (in, out, ReadAvailHandler, WriteDoneHandler, 0);
}
SynchConsole::~SynchConsole(){
    delete console;

    delete consoleChar;
    delete consoleString;
    delete writeDone;
    delete readAvail;
}
void SynchConsole::SynchPutChar(int ch){
    consoleChar->P ();
    console->PutChar (ch);
    writeDone->P ();
    consoleChar->V ();
}
int SynchConsole::SynchGetChar(){
    consoleChar->P ();
    readAvail->P ();
    int ret = console->GetChar ();
    consoleChar->V ();
    return ret;
}
void SynchConsole::SynchPutString(const char s[]){
    consoleString->P ();
    int i = 0;

    while(s[i] != '\0'){
        SynchPutChar (s[i]);
	    i++;
    }
    consoleString->V ();
}
void SynchConsole::SynchGetString(char* s, int n){
    consoleString->P ();
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
    consoleString->V ();
}
#endif // CHANGED
