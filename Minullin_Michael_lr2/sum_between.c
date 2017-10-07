
#include "sum_between.h"

#include "index_first_zero.h"
#include "index_last_zero.h"

#include <stdlib.h>

int sum_between(int arr[], int arr_size) {
    int from = index_first_zero(arr, arr_size);
    int to = index_last_zero(arr, arr_size);
    int result = 0;
    int i;
    for (i = from; i < to; ++i)
        result += abs(arr[i]);
    return result;
}
