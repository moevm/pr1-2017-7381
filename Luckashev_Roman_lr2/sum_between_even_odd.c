#include <stdlib.h>
#include "index_first_even.h"
#include "index_last_odd.h"

long sum_between_even_odd(int* a, int i){
 int first = index_first_even(a,i);
 int last = index_last_odd(a,i);
 long sum = 0;
  if((first!=-1) && (last!=-1)){
   for(int j = first; j < last; j++){
    sum+=abs(a[j]);
   }
   return sum;
  }
return -1;
}
