
#include "sum_between_even_odd.h"
#include "index_first_even.h"
#include "index_last_odd.h"

#include <stdlib.h>

int sum_between_even_odd(int arr[], int arr_size) {
    int a = index_first_even(arr, arr_size);
    int b = index_last_odd(arr, arr_size);
    int sum = 0;
    int i;
    for (i = a; i < b; ++i) 
        sum += abs(arr[i]);
    return sum;
}