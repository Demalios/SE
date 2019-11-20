#ifdef CHANGED

#include "copyright.h"
#include "pageprovider.h"


PageProvider::PageProvider(int nbItems)
{
  map = new BitMap(nbItems);
  
  nbPages = nbItems;
  pages = new TranslationEntry[nbPages];

  for(int i = 0; i < nbPages; i++)
    {
      pages[i].physicalPage = i+1;
      pages[i].valid = TRUE;
      pages[i].use = FALSE;
      pages[i].dirty = FALSE;
      pages[i].readOnly = FALSE;
    }
}


PageProvider::~PageProvider()
{
  delete map;
  delete [] pages;
}


int PageProvider::GetEmptyPage()
{
  if(map->NumClear() > 0)
    {
      int pageLibre = map->Find();
	    
      memset (&pages[pageLibre], 0, sizeof(TranslationEntry));
      return pageLibre;
    }
  return -1;
}


void PageProvider::ReleasePage(int ind)
{
  map->Clear(ind);
}


int PageProvider::NumAvailPage()
{
  return map->NumClear();
}

int PageProvider::GetNbPages()
{
  return nbPages;
}

TranslationEntry *PageProvider::GetPages()
{
  return pages;
}

#endif // CHANGED
