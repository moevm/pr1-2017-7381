#include "index_first_negative.h"

int index_first_negative( int mas[] , int size )
{
  int i=0;
  while ( i < size )
    {
      if ( mas[i] < 0 )
	{
	  return i;
          i=i+101;
	}
      i++;
    }
}
