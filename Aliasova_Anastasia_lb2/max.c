#include "max.h"

int max( int  arr[], int size ) {

	int max = 0;
        int i;
        for (i = 0; i < size; i++) {
                if (arr[i] > max) {
                        max = arr[i];
                }
        }
return max;
}

