#include <stdlib.h>
#include "sum_before_and_after.h"
#include "index_first_zero.h"
#include "index_last_zero.h"

int sum_before_and_after(int arr[], int arr_size) {
    int to = index_first_zero(arr, arr_size);
    int from = index_last_zero(arr, arr_size);
    int sum = 0;
    for (int i = 0; i < to; i++)
        sum += abs(arr[i]);
    for (int i = from; i < arr_size; i++)
        sum += abs(arr[i]);
    return sum;
}