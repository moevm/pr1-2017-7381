#include <stdio.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "sum_before_and_after_negative.h"
#include "sum_between_negative.h"

int main()
{
  int i=0;
  int operation_number , res;
  char c;
  int mas[100];
  scanf( "%d%c", &operation_number , &c );
  scanf( "%d%c", &mas[0] , &c );
  while (c!='\n')
    {
      i++;
      scanf( "%d%c" , &mas[i] , &c );
    }
  i++;
  res = 0;
  switch ( operation_number )
    {
      case 0: res = index_first_negative( mas  , i );
              printf("%d", res );
              break;
      case 1: res = index_last_negative ( mas  , i );
              printf("%d", res );
              break;
      case 2: res = sum_between_negative ( mas  , i );
              printf("%d", res );
              break;
      case 3: res = sum_before_and_after_negative ( mas , i );
              printf("%d", res );
              break;
      default: printf("Данные некоректны");
    }
}

