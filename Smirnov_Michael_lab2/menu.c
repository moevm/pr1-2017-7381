#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "index_first_zero.h"
#include "index_last_zero.h"
#include "sum_between.h"
#include "sum_before_and_after.h"

int main()
{
int vybor;
int mas[100];
char c;
int i=0;
scanf("%d%с",&vybor,&c);
while (c!='\n')
{
    scanf("%d%c",&mas[i],&c);
    i++;
}
i--;
switch(vybor)
{
    case 0:
        printf("%d\n",index_first_zero(mas,i));
        break;
    case 1:
        printf ("%d\n",index_last_zero(mas,i));
        break;
    case 2:
        printf ("%d\n",sum_between(mas,i));
        break;
    case 3:
        printf ("%d\n",sum_before_and_after(mas,i));
        break;
    default:
        printf ("Данные некорректны\n");
}

    return 0;
}
