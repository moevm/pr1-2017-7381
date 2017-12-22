#include <stdio.h>
#include "min.h"

int sum(int mas[], int size) {

	int min_el = min(mas, size);
	int i = 0;
	int sum = 0;
	while (mas[i] != min_el) {
		sum+=mas[i];
		i++;
    }

return sum;
}

