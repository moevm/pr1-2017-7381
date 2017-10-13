
#include "sum_before_and_after.h"

#include "index_first_zero.h"
#include "index_last_zero.h"

#include <stdlib.h>

int sum_before_and_after(int arr[], int arr_size) {
    int to = index_first_zero(arr, arr_size);
    int from = index_last_zero(arr, arr_size);
    int result = 0;
    int i;
    for (i = 0; i < to; ++i)
        result += abs(arr[i]);
    for (i = from; i < arr_size; ++i)
        result += abs(arr[i]);
    return result;
}

