#include "index_first_negative.h"

int index_first_negative(int mas[], int ssize)
{
	int i;
    for(i=0;i<ssize;i++)
    {
        if (mas[i]<0)
            return i;
    }
    return -1;
}
