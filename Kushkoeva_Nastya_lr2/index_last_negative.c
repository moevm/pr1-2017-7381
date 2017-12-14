#include <stdio.h>
#include "index_last_negative.h"
int index_last_negative(int a[], int i){
int last, index;
for(index=1; index<i+1; index++)
{
if(a[index]<0)
last=index;
}
return last-1;
}

