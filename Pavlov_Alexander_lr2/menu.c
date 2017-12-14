#include <stdio.h>
#include "sum_between.h"
#include "index_first_zero.h"
#include "index_last_zero.h"
#include "sum_before_and_after.h"

int main()
{
    int N, i = 0;
    int arr[100];
    char k;
    scanf("%d", &N);
    do
    {
        scanf("%d%c", &arr[i], &k);
        i++;
    } while (k != '\n');

    switch (N)
    {
    case 0:
        printf("%d", index_first_zero(arr, i));
        break;
    case 1:
        printf("%d", index_last_zero(arr, i));
        break;
    case 2:
        printf("%d", sum_between(arr, i));
        break;
    case 3:
        printf("%d", sum_before_and_after(arr, i));
        break;
    default:
        printf("Данные некорректны");
    }
    return 0;
}
