#ifdef CHANGED
class PageProvider
{
    private:
    BitMap *map;
    int nbPages;
    TranslationEntry *pages;

    public:
    PageProvider();
    ~PageProvider();
    void GetEmptyPage();
    void ReleasePage();
    int NumAvailPage();
};
#endif