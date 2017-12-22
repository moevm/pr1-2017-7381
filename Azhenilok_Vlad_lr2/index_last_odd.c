
#include "index_last_odd.h"

int index_last_odd(int arr[], int arr_size) {
    int i;
    for (i = arr_size - 1; i >= 0; --i)
        if (arr[i] & 1)
            return i;
}