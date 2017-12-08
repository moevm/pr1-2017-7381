#include <stdio.h>
#include "min.h"

int sum(int arr[], int size) {

	int minimal = min(arr, size);
	int i = 0;
	int sum = 0;
	while (arr[i] != minimal) {
		sum+=arr[i];
		i++;
    }

return sum;
}

