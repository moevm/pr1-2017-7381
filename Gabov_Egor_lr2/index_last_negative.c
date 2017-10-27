#include "index_last_negative.h"

int index_last_negative ( int  mas[] , int size )

{

  int i=1;
  while ( i < size )
    {
      if ( mas[size-i] < 0 )
	{
	  return size-i;
	  i=i+100;
	}
      i++;
    }
}
