#include <stdio.h>
#include <stdlib.h>
#include "index_last_negative.h"

int index_last_negative(int a[], int length)
{
        int i, neg;

        for (i=length-1; i>=0; i--)
        {
                if(a[i] < 0)
                {
                        neg = i;
			return neg;
			break;
                }
        }
}

