#include <stdio.h>
#include "multi_between_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"
void multi_between_negative(int a[], int i){
int between=1, index;
for(index=index_first_negative(a, i)+1; index<index_last_negative(a,i)+1; index++){
between=a[index]*between;
}
printf("%d\n", between);
}
