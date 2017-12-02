#include "index_first_zero.h"

int index_first_zero(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++)
        if (arr[i] == 0)
            return i;
}