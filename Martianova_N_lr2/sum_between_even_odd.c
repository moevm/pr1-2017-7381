#include<stdlib.h>
#include"index_first_even.h"
#include"index_last_odd.h"
int sum_between_even_odd(int a[],int i){
int sum,t;
sum=0;
int n=index_first_even(a,i)+1;
int k=index_last_odd(a,i)+1;
for(t=n;t<k;++t){
	sum+=abs(a[t]);
	}
return sum;
}
