#include <stdlib.h>
#include "index_first_even.h"
#include "index_last_odd.h"

long sum_before_even_and_after_odd(int* a, int i){
 int first = index_first_even(a,i);
 int last = index_last_odd(a,i);
 long sum = 0;
  if((first != -1) && (last != -1)){
   for(int j = 0; j < first; j++) sum+=abs(a[j]);
   for(int k = i - 1; k >= last; k--) sum+=abs(a[k]);
   return sum;
  }
 return -1;
}
