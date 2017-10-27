#include "sum_between_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"


int sum_between_negative( int mas[] , int size )
{
  int first , last;
  int sum=0;
  int i=0;
  first=index_first_negative( mas , size );
  last=index_last_negative( mas , size );
  i = first;
  while ( i < last )
    {
      sum+=abs(mas[i]);
      i++;
    }
  return sum;
}
