#include "index_first_zero.h"
int index_first_zero(int* mass, int size) {
    int i;
    for (i = 0; i < size; i++)
        if (mass[i] == 0)
            return i;
}
