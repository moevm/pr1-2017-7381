#include <stdio.h>
#include <stdlib.h>
#include "index_first_even.h"
#include "index_last_odd.h"
void sum_before_even_and_after_odd (int arr[], int size){
	int i, even, odd;	
	even=index_first_even(arr, size);
	odd=index_last_odd(arr, size);
	int sum_even=0, sum_odd=0;
	for (i=0;i<even;i++)
	sum_even += abs(arr[i]);
	for (i=size;odd<=i;i--)
	sum_odd += abs(arr[i]);
	printf("%d\n",sum_odd+sum_even);
}
