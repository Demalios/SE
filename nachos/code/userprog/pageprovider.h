#ifdef CHANGED

#include "bitmap.h"
#include "translate.h"

class PageProvider
{
    public:
    PageProvider(int nbItems);
    ~PageProvider();
    int GetEmptyPage();
    void ReleasePage(int ind);
    int NumAvailPage();
    int GetNbPages();
    TranslationEntry *GetPages();

    private:
    BitMap *map;
    int nbPages;
    TranslationEntry *pages;
};

#endif // CHANGED
