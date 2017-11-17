#include "index_last_odd.h"

int index_last_odd(int* a, int i){
 while(i>0)
  if(a[--i]%2)
   return i;
 return -1;
}
