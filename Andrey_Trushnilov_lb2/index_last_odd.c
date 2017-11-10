#include <stdio.h>

int index_last_odd(int *a, int len){


int i;
int max;
 
 

   for(i=0;i<len;i++) {
      if(a[i] % 2 !=0) {
       
        max=i;
      }
    
 }

return max;

}



