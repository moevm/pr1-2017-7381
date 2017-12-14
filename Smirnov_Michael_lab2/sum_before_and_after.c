#include <stdio.h>
#include <stdlib.h>
#include "index_first_zero.h"
#include "index_last_zero.h"

int sum_before_and_after(int mas[],int i)
{
    int a=0,b=0,zero,sub;
    int fir = index_first_zero(mas,i);
    int las = index_last_zero(mas,i);

    for(zero=0;zero<fir;++zero)
    {
        a+=abs(mas[zero]);
    }
    zero=0;
    for(zero=las;zero<=i;++zero)
    {
        b=b+abs(mas[zero]);
    }
    sub=a+b;

    return sub;
}
