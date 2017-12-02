#include <stdio.h>
int index_first_even (int arr[], int size){
	int i;
	for (i=0; i<=size; i++)
		if (arr[i]%2==0) 
		break; 
return i;
}
