#include <stdio.h>
#include "index_first_even.h"
#include "index_last_odd.h"
#include "sum_between_even_odd.h"
#include "sum_before_even_and_after_odd.h"

int main(){
int arr[100];
int i=0;
char c;
int input=0;
int out=0;

 scanf("%d", &input);
   while ( c != '\n'){
     scanf("%d%c", &arr[i], &c);
     i++;
   }

 switch(input){
   case 0:
     out=index_first_even(arr, i);
     printf("%d\n",out);
     break;
   case 1:
     out=index_last_odd(arr, i);
     printf("%d\n",out);
     break;
   case 2:
     out=sum_between_even_odd(arr, i);
     printf("%d\n",out);
     break;
   case 3:
     out=sum_before_even_and_after_odd(arr, i);
     printf("%d\n",out);
     break;
    default:
        printf("Данные некорректны\n");
 }
return 0;
}
