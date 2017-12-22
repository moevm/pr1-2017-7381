#include <stdio.h>
#include "min.h"

int min(int arr[], int size) {

        int min = arr[0];
        int i;
        for (i = 1; i < size; i++) {
            if (arr[i] < min) {
				min = arr[i];
			}
        }
return min;
}

