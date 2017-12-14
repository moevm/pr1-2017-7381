#include <stdlib.h>
#include <stdio.h>
#include "index_first_even.h"
#include "index_last_odd.h"
void sum_between_even_odd (int arr[], int size){
	int sum, even, odd;
	even=index_first_even(arr, size);
	odd=index_last_odd(arr, size);
	for (sum=0; even<odd;even++)
	sum+=abs(arr[even]);
	printf("%d\n", sum);
}
