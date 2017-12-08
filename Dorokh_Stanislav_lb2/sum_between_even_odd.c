#include <stdlib.h>
#include "index_first_even.h"
#include "index_last_odd.h"

int sum_between_even_odd(int arr[], int k){

int sum=0;
int i=0;

  for (i=(int)index_first_even(arr, k);i<(int)index_last_odd(arr, k);i++){
    sum=sum+ abs(arr[i]);
  }

return sum;

}
