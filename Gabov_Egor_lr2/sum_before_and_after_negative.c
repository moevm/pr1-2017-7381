#include "sum_before_and_after_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"
#include <stdlib.h>

int sum_before_and_after_negative( int mas[] , int size )
{
  int first,last;
  int i = 0 ;
  int sum = 0;
  first = index_first_negative ( mas , size );
  while ( i < first )
    {
      sum+=mas[i];
      i++;
    }
  i = index_last_negative ( mas , size );
  while ( i < size )
    {
      sum+=abs(mas[i]);
      i++;
    }
  return sum;
}

