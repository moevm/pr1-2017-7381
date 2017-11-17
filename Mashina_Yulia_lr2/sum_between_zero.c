#include <stdlib.h>
#include "index_first_zero.h"
#include "index_last_zero.h"

int sum_between_zero(int arr[], int i)
{
    int first, last;
    first = index_first_zero(arr, i);
    last = index_last_zero(arr, i);
    int k, sum1 = 0;
    for (k = first + 1; k < last + 1; k++)
    {
        sum1 = sum1 + abs(arr[k]);
    }
    return sum1;
}
