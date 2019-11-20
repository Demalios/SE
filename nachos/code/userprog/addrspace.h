// addrspace.h 
//      Data structures to keep track of executing user programs 
//      (address spaces).
//
//      For now, we don't keep any information about address spaces.
//      The user level CPU state is saved and restored in the thread
//      executing the user program (see thread.h).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef ADDRSPACE_H
#define ADDRSPACE_H

#include "copyright.h"
#include "filesys.h"
#include "translate.h"
#include "noff.h"
#include "list.h"
#ifdef CHANGED
#include "pageprovider.h"
#endif // CHANGED

#define UserStacksAreaSize		1024	// increase this as necessary!

class AddrSpace:dontcopythis
{
  public:
    AddrSpace (OpenFile * executable);	// Create an address space,
    // initializing it with the program
    // stored in the file "executable"
    ~AddrSpace ();		// De-allocate an address space

    void InitRegisters ();	// Initialize user-level CPU registers,
    // before jumping to user code

    void SaveState ();		// Save/restore address space-specific
    void RestoreState ();	// info on a context switch 

    unsigned Dump(FILE *output, unsigned virtual_x, unsigned virtual_width,
		    unsigned physical_x, unsigned virtual_y, unsigned y,
		    unsigned blocksize);
				// Dump program layout as SVG
#ifdef CHANGED
    unsigned NumPages() { return pageP->GetNbPages(); }
#else
    unsigned NumPages() { return numPages; }
#endif // CHANGED
#ifdef CHANGED
    int AllocateUserStack();
#endif //CHANGED
    
  private:
    NoffHeader noffH;		// Program layout

#ifdef CHANGED
    PageProvider *pageP;
#else
    TranslationEntry * pageTable; // Page table
    unsigned int numPages;	// Number of pages in the page table
#endif // CHANGED
};

extern List AddrspaceList;

#endif // ADDRSPACE_H
