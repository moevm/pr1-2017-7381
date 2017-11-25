#include "index_first_even.h"

int index_first_even(int* a, int i){
 int j = 0;
  while(j<i)
   if(a[j++]%2==0)
    return --j;
 return -1;
}
