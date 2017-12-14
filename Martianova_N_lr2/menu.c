#include<stdio.h>
#include "index_first_even.h"
#include"index_last_odd.h"
#include"sum_between_even_odd.h"
#include"sum_before_even_and_after_odd.h"
int main()
{
int i,a[100],n;
char m;
i=0;
do{scanf("%d%c", &a[i],&m);i++;}
while(m!='\n');
switch(a[0]){
case 0:printf("%d\n",index_first_even(a,i)); break;
case 1:printf("%d\n",index_last_odd(a,i));break;
case 2:printf("%d\n",sum_between_even_odd(a,i)); break;
case 3:printf("%d\n",sum_before_even_and_after_odd(a,i)); break;
default: printf("Данные некорректны\n");
}
return 0;
}
