#include <stdlib.h>
#include "index_first_even.h"
#include "index_last_odd.h"

int sum_before_even_and_after_odd(int arr[], int k){

int sum=0;
int i=0;

 for (i=0;i<index_first_even(arr,k);i++)
   sum = sum + abs(arr[i]);
 for (i=index_last_odd(arr,k);i<k;i++)
   sum = sum + abs(arr[i]);

return sum;
}
