#include <stdio.h>
#include "index_first_negative.h"
int index_first_negative(int a[], int i){
int index, first;
int flag=1;
for(index=1; (index<i)&&(flag==1); index++)
	{
	if(a[index]<0){
		first=index-1;
		flag=0;
		}
	}
return first;
}
