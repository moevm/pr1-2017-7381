#include "index_last_zero.h"

int index_last_zero(int arr[], int arr_size) {
    for (int i = arr_size-1; i >= 0; i++)
        if (arr[i] == 0)
            return i;
}