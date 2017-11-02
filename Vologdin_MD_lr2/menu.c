#include <stdio.h>
#include <stdlib.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "sum_between_negative.h"
#include "sum_before_and_after_negative.h"
#include <math.h>

int main()
{
    int n;
    char t,y;
    int array[100];
    int i=1;
    scanf_s("%d%c",&n,&y);
    scanf_s("%d",&array[0]);
    t = getchar();
    while (t!= '\n')
    {
        scanf("%d%c",&array[i],&t);
        i++;
    }
    switch (n)
    {
    case 0:
        printf("%d",index_first_negative(array,i));
        break;
    case 1:
        printf("%d",index_last_negative(array,i));
        break;
    case 2:
        printf("%d",sum_between_negative(array,i));
        break;
    case 3:
		printf("%d", sum_before_and_after_negative(array, i));
        break;
    default:
        printf("Данные некорректны");
    }
    return 0;
}
