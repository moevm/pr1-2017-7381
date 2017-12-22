#include "max.h"

int max( int  mas[], int size ) {

	int max = 0;
        int i;
        for (i = 0; i < size; i++) {
                if (mas[i] > max) {
                        max = mas[i];
                }
        }
return max;
}

