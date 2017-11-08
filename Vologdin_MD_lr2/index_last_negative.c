#include "index_last_negative.h"

int index_last_negative(int mas[], int ssize)
{
	int i;
	for (i = (ssize - 1); i >= 0; i--)
	{
		if (mas[i]<0)
			return i;
	}
	return -1;
}