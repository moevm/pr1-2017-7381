#include <stdio.h>
#include "index_last_odd.h"
int ilo(int a[100],int i)
{
int index;
for(index=i;index>0;index--)
{
if(a[index]%2!=0)
{
return index;
}
}
}
