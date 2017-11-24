#include <stdio.h>
int index_last_odd (int arr[], int size){
	int i;
	for (i=size; i>=0; i--)
		if (arr[i]%2==1)
			break;
return i;
}
