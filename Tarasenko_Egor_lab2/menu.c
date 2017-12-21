#include <stdio.h>
#include <stdlib.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "multi_between_negative.h"
#include "multi_before_and_after_negative.h"

int main()
{
	int length = 0;
	char c;
	int a[100];
	int type_of_operation;

	scanf("%d", &type_of_operation);

	while(c!='\n')
	{
		scanf("%d%c", &a[length], &c);
		length++;
	}

	switch(type_of_operation)
	{
		case 0:
			printf("%d\n", index_first_negative(a, length));
			break;

                case 1:
                        printf("%d\n", index_last_negative(a, length));
                        break;

                case 2:
                        printf("%d\n", multi_between_negative(a, length));
                        break;

                case 3:
                        printf("%d\n", multi_before_and_after_negative(a, length));
                        break;

		default:
			printf("Data is not correct!\n");
			break;
	}

	return 0;
}
