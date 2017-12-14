#include <stdio.h>
#include "multi_before_and_after_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"
void multi_before_and_after_negative(int a[], int i){
int index, multi1=1, multi2=1;
for(index=1; index<index_first_negative(a, i)+1; index++)
multi1=multi1*a[index];
for(index=index_last_negative(a, i)+1; index<=i; index++)
multi2=multi2*a[index];
printf("%d\n", (multi1*multi2));
}
