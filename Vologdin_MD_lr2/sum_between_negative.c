#include "sum_between_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"
#include <math.h>

int sum_between_negative(int mas[], int ssize)
{
    int i,k=0;
    for(i=index_first_negative(mas,ssize); i<index_last_negative(mas,ssize);i++)
        k+=abs(mas[i]);
    return k;
}
