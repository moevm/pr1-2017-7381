#include <stdio.h>
#include "index_first_even.h"
#include "index_last_odd.h"
#include "sum_between_even_odd.h"
#include "sum_before_even_and_after_odd.h"

int main(){
 int N;
 char c;
 scanf("%d", &N);
 int a[100];
 int i = 0;
	while (c!='\n'){
	 scanf("%d%c", &a[i++], &c);
	}
 long command = 0;
	switch(N){
	 case 0:
		command = (long)index_first_even(a,i); break;
	 case 1:
		command = (long)index_last_odd(a,i); break;
	 case 2:
		command = sum_between_even_odd(a,i); break;
	 case 3:
		command = sum_before_even_and_after_odd(a,i); break;
	 default:
		command = -1;
	}
 if(command == -1){
 printf("Данные некорректны\n");
 return 0;
 }
 printf("%ld\n", command);
 return 0;
}
