#include <stdio.h>
#include "max.h"
#include "min.h"
#include "diff.h"

int diff(int arr[], int size) {
	int maximal, minimal;
	maximal = max(arr, size);
	minimal = min(arr, size);
	int diff = maximal - minimal;
return diff;
}
