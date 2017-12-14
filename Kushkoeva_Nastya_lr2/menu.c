#include <stdio.h>
#include <stdlib.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "multi_between_negative.h"
#include "multi_before_and_after_negative.h"
int main(){
int  i=0;
char c;
int a[100];
while(c!='\n')
{
scanf("%d%c", &a[i], &c);
i++;
}
i=i-1;
switch(a[0]){
	case 0:
printf("%d\n", index_first_negative(a, i));
break;
	case 1:
printf("%d\n", index_last_negative(a,i));
break;
	case 2:
multi_between_negative(a,i);
break;
	case 3:
multi_before_and_after_negative(a,i);
break;
	default:
printf("Данные некорректны\n");
 }
return 0;
}
