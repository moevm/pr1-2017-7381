#include <stdio.h>
#include <stdlib.h>
#include "index_first_even.h"
#include "index_last_odd.h"
#include "sum_between_even_odd.h"
int sbeo(int a[100])
{
int n,sum;
sum=0;
for(n=ife(a);n<ilo(a);n++)
{
sum+=abs(a[n]);
}
return sum;
}
