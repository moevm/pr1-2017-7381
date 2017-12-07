#include <stdio.h>
#include "max.h"
#include "min.h"
#include "diff.h"

int diff(int mas[], int size) {
	int max_el, min_el;
	max_el = max(mas, size);
	min_el = min(mas, size);
	int diff = max_el - min_el;
return diff;
}
