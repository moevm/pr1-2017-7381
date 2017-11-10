
#include "index_first_even.h"
#include "index_last_odd.h"
#include "sum_between_even_odd.h"
#include "sum_before_even_and_after_odd.h"
#include <stdio.h>


int main(){
int a[100] = {};
int i=0;
int c;
int var;
int number=0;


scanf("%d",&var);
 while( ((c=getchar())) !='\n'){
     ungetc(c,stdin);
     scanf("%d",&i);
    a[number++]=i;
    }

switch(var){
    case 0:
        printf("%d\n", index_first_even(a,number));
        break;
    
    case 1:
        printf("%d\n", index_last_odd(a,number));
        break;
    
    case 2:
        printf("%d\n", sum_between_even_odd(a,number));
        break;
    
    case 3:
        printf("%d\n", sum_before_even_and_after_odd(a,number));
        break;
    default:
        printf("Данные некорректны");
        break;


}


return 0;
}
