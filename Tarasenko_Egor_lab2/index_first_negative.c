#include <stdio.h>
#include <stdlib.h>
#include "index_first_negative.h"

int index_first_negative(int a[], int length)
{
	int i, neg;

	for (i=0; i<length; i++)
	{
		if(a[i] < 0)
		{
			neg = i;
			return neg;
		}
	}
}
