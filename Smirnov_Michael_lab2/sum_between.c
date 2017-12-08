#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "index_first_zero.h"
#include "index_last_zero.h"

int sum_between(int mas[],int i)
{
    int beatsum=0,zero;
    int fir = index_first_zero(mas,i);
    int las = index_last_zero(mas,i);
    for(zero=fir;zero<las;++zero)
    {
        beatsum=beatsum+abs(mas[zero]);
    }
    return beatsum;
}


