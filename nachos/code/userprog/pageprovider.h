#ifdef CHANGED

#ifndef PAGEPROVIDER_H
#define PAGEPROVIDER_H

#include "bitmap.h"

class PageProvider:dontcopythis
{
    public:
    PageProvider();
    ~PageProvider();

    /**
     * task : gets index of an empty page
     * return : the index of an empty page
    **/
    int GetEmptyPage();


    /**
     * task : free memory used by a page
     * return : none
     * ind : index of the page to release
    **/
    void ReleasePage(int ind);


    /**
     * task : gets the number of avail pages
     * return : the number of avail pages
    **/
    int NumAvailPage();


    private:
    BitMap *map;
};

#endif // PAGEPROVIDER_H

#endif // CHANGED
