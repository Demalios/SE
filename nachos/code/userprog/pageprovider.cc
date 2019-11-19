#ifdef CHANGED

#include "copyright.h"


class PageProvider
{
    public:
    PageProvider::PageProvider(int nbItems)
    {
        BitMap *map = new Bitmap(nbItems);

        nbPages = nbItems;
    }


    ~PageProvider::PageProvider()
    {
        delete [] page;
    }


    void PageProvider::GetEmptyPage()
    {

    }


    void PageProvider::ReleasePage()
    {
        
    }


    int PageProvider::NumAvailPage()
    {
        return 0;
    }
};


#endif