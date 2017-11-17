#include "index_first_zero.h"
#include "index_last_zero.h"

int sum_before_and_after(int* mass, int size){
    int first = index_first_zero(mass, size),
        last = index_last_zero(mass, size),
        result = 0,
        i = 0;
    for (; i < size; i++){
        if(i == first)
            i = 1+last;
        result += (mass[i] > 0 ? mass[i] : -mass[i]);
        }
    return result;
}


