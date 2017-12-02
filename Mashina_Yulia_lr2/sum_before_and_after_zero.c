#include <stdlib.h>
#include "index_first_zero.h"
#include "index_last_zero.h"

int sum_before_and_after_zero(int arr[], int i)
{
    int first, last;
    first = index_first_zero(arr, i) + 1;
    last = index_last_zero(arr, i) + 1;
    int k, sum2, sum21 = 0, sum22 = 0;
    for (k = 1; k < first; k++)
    {
        sum21 = sum21 + abs(arr[k]);
    }
    for (k = i; k >= last; k--)
    {
        sum22 = sum22 + abs(arr[k]);
    }
    sum2 = sum21 + sum22;
    return sum2;
}
