#include <stdlib.h>
#include "sum_between.h"
#include "index_first_zero.h"
#include "index_last_zero.h"

int sum_between(int arr[], int arr_size) {
    int from = index_first_zero(arr, arr_size);
    int to = index_last_zero(arr, arr_size);
    int sum = 0;
    for (int i = from; i < to; i++)
        sum += abs(arr[i]);
    return sum;
}