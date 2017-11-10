#include <stdio.h>

int index_first_even(int *a, int len){
 
int i;
int min;

 for(i=0;i<len;i++) {
      if(a[i] % 2 ==0){
          min=i;
      
      break;}
}
return min;
}
