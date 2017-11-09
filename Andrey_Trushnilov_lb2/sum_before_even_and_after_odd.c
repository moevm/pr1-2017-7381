#include "index_first_even.h"
#include "index_last_odd.h"

#include <stdlib.h>

int sum_before_even_and_after_odd(int *a, int len){
    int i;
    int sum1=0,sum2=0,sum3;
    
    for(i=0;i<index_first_even(a,len);i++){
        sum1 +=abs(a[i]);
  
    }

    for(i=index_last_odd(a,len);i<=len;i++){
        sum2 +=abs(a[i]);
    
    }
    sum3=sum1+sum2;
    return sum3;

}
