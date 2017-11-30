#include "index_first_zero.h"
#include "index_last_zero.h"
#include "sum_between.h"

int sum_between(int mass[], int size) {
    int first = index_first_zero(mass, size),
        last = index_last_zero(mass, size),
        result = 0,
        i = first;
    for (; i < last; i++)
        result += (mass[i]>0 ? mass[i] : -mass[i]);
    return result;
}
