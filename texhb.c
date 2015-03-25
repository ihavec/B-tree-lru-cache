#include "stdafx.h"
#include "techb.h"

/* return true/false */
/* i in (0, tch_blks_count-1) */
eTBState   techb_bit (IN sDB *db, IN uint_t index, IN bool set, IN bool bit)
{

 uint_t  byte  = index / (BITSINBYTE);
 uint_t  ipage = index / (BITSINBYTE * db->head_.page_size_);
 //-----------------------------------------
 db->techb_arr_[ipage].memory_

 byte &= (1U << (index % BITSINBYTE));
 //-----------------------------------------
 return byte ? NODE : FREE;
}

// bool techb_read  (IN sTechB *techb) { return true; }
// bool techb_write (IN sTechB *techb)
eDBState   techb_sync (IN sDB     *db)
{ return FAIL;


}

void       techb_destroy (IN sTechB  *techb)
{
 free (techb->memory_);
}
sTechB*    techb_create  (IN sDB     *db,
                          IN uchar_t *memory,
                          IN uint_t   offset)
{
 bool result = 0;

 sTechB *techb = (sTechB*) memory;
 if ( techb )
 {
  techb->size_   = db->head_.page_size_;
  techb->offset_ = offset;
  techb->dirty_  = false;

  techb->memory_ = calloc (techb->size_, sizeof (uchar_t));
  if ( !techb->memory_ )
  {
   errno = ENOMEM;
   result = true;
   goto end;
  }
//  result = techb_read (&techb);
 }

end:;
 if ( result )
 {
  techb_destroy (techb);
  techb = NULL;
 }
 return techb;
}