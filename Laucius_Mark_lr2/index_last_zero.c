#include <index_last_zero.h>
int index_last_zero(int mass[], int size) {
    int i;
    for (i = size-1; i>=0; i--)
        if (mass[i] == 0)
            return i;
}
