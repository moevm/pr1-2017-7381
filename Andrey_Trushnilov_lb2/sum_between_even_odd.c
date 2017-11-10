#include "index_first_even.h"
#include "index_last_odd.h"

#include <stdlib.h>

 int sum_between_even_odd(int *a, int len){
    int sum=0;
    int i;
    
    for(i=index_first_even(a,len);i<index_last_odd(a,len);i++){
        sum +=abs(a[i]);
    
    }
    return sum;

}
