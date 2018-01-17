#include <stdio.h>
#include "index_first_even.h"
#include "index_last_odd.h"
#include "sum_between_even_odd.h"
#include "sum_before_even_and_after.h"
int main()
{

int i;
int e;
int k, m, a[100];
char t;
scanf("%d",&m);

for(i=0;i<100;i++)
{
scanf("%d%c", &a[i], &t);
if(t=='\n')
{
break;
}
}
switch(m)
{
case 0:
printf("%d\n",ife(a,i));
break;
case 1:
printf("%d\n",ilo(a,i));
break;
case 2:
printf("%d\n",sbeo(a,i));
break;
case 3:
printf("%d\n",sbeaa(a,i));
break;
default:
printf("Данные некорректны");
break;
}
}
