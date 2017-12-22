#include <stdio.h>
#include "min.h"

int min(int mas[], int size) {

        int min = mas[0];
        int i;
        for (i = 1; i < size; i++) {
            if (mas[i] < min) {
				min = mas[i];
			}
        }
return min;
}

