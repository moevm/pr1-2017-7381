#include <stdio.h>

int index_first_zero(int mas[],int i)
{

int pierre;
for(pierre=0;pierre<=i;++pierre)
{
    if(mas[pierre]==0)
        break;
}


        return pierre;
}
