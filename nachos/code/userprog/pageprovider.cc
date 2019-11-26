#ifdef CHANGED

#include "system.h"
#include "pageprovider.h"

PageProvider::PageProvider()
{
  map = new BitMap(NumPhysPages);
}


PageProvider::~PageProvider()
{
  delete map;
}


int PageProvider::GetEmptyPage()
{
  DEBUG('a', "Entering GetEmptyPage \n");
  
  DEBUG('a', "map : %p\n", map);
  DEBUG('a', "NumClear : %d\n", map->NumClear());

  if(map->NumClear() > 0)
    {
      int freePage = map->Find();
      DEBUG('a', "freePage : %d\n", freePage);
	    
      memset (&machine->mainMemory[freePage * PageSize], 0, PageSize);
      return freePage;
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

#endif // CHANGED
