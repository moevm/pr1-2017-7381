#include <stdlib.h>
#include "index_first_zero.h"
#include "index_last_zero.h"

int sum_between(int arr[], int i)
{
    int first, last;
    first = index_first_zero(arr, i)+1;
    last = index_last_zero(arr, i)-1;
    int k, sum1 = 0;
    for (k = first; k <= last; k++)
    {
        sum1 = sum1 + abs(arr[k]);
    }
    return sum1;
}
