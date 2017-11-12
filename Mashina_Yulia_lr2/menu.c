#include <stdio.h>
#include <locale.h>
#include "sum_between_zero.h"
#include "index_first_zero.h"
#include "index_last_zero.h"
#include "sum_before_and_after_zero.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    int i = 0;
    int arr[100];
    char t;
    do
    {
        scanf("%d%c", &arr[i], &t);
        i++;
    } while (t != '\n');
    i = i - 1;

    switch (arr[0])
    {
    case 0:
        printf("%d", index_first_zero(arr, i));
        break;
    case 1:
        printf("%d", index_last_zero(arr, i));
        break;
    case 2:
        printf("%d", sum_between_zero(arr, i));
        break;
    case 3:
        printf("%d", sum_before_and_after_zero(arr, i));
        break;
    default:
        printf("Данные некорректны");
    }
    return 0;
}
