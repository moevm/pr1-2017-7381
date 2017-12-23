#include <stdio.h>
#include <stdlib.h>
#include "sum_before_even_and_after.h"
#include "index_first_even.h"
#include "index_last_odd.h"
int sbeaa(int a[100],int i)
{
int n, k ,sum, sum1, sum2;
sum1=0;
sum2=0;
for(n=ife(a)-1; n>=0; n--)
{
sum1+=abs(a[n]);
}

for(k=ilo(a); k<=i;k++)
{
sum2+=abs(a[k]);
}
sum=sum1+sum2;
return sum;
}
