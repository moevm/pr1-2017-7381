#include <stdio.h>
#include <stdlib.h>
#include "multi_before_and_after_negative.h"
#include "index_first_negative.h"
#include "index_last_negative.h"

int multi_before_and_after_negative(int a[], int length)
{
        int i, first_neg, last_neg;
        int multi = 1;

        first_neg = index_first_negative(a, length);
        last_neg = index_last_negative(a, length);

        for (i=0; i<length; i++)
        {
                if(((i>=0) && (i<first_neg)) || ((i>=last_neg) && (i<=length)))
                {
                        multi = multi * a[i];
                }
        }

        return multi;
}

