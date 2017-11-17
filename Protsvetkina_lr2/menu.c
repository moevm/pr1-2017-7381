#include <stdio.h> 
#include "index_first_even.h"
#include "index_last_odd.h"
#include "sum_between_even_odd.h"
#include "sum_before_even_and_after_odd.h"

int main(void){
	int num;
	int i=0, j=0; 
	int arr[100];
	scanf("%d",&num);
	while ((getchar())!='\n')
		scanf("%d",&arr[i++]);
	switch (num){
		case 0: printf("%d",index_first_even(arr, i-1));
				 break;
		case 1: printf("%d", index_last_odd(arr, i-1));
				 break; 
		case 2: sum_between_even_odd(arr, i-1);
				 break; 
		case 3: sum_before_even_and_after_odd(arr, i-1);
				 break; 
		default: printf("Данные некорректны");
	}
}

