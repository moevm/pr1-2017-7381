#include<stdlib.h>
#include"index_first_even.h"
#include"index_last_odd.h"
int sum_before_even_and_after_odd(int a[],int i){
int sum,sum1=0,sum2=0,t;
int n=index_first_even(a,i)+1;
int k=index_last_odd(a,i)+1;
sum=0;
for(t=1;t<n;t++){sum1+=abs(a[t]);}
for(t=k;t<i;t++){sum2+=abs(a[t]);}
sum=sum1+sum2;
	
return sum;
}
