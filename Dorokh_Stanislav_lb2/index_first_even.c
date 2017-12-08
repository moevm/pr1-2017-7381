#include <stdio.h>

int index_first_even(int arr[], int k){
int first=0;
int i=0;

 for (i=0;i<k;i++){
   if (arr[i] % 2 ==0)
    {first = i;
    break;
   }
 }

return first;
}
