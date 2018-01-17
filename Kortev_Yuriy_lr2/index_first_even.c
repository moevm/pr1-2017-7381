#include <stdio.h>
#include "index_first_even.h"
int ife(int a[100], int i)
{
int n;
for(n=0;n<i;n++)
{
if(a[n]%2==0)
{
return n;
}
}
}
