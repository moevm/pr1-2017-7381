
#include "index_first_even.h"
#include "index_last_odd.h"
#include "sum_between_even_odd.h"
#include "sum_before_even_and_after_odd.h"

#include <stdio.h>

int arr[100];
int arr_size = 0;
int query;
char c;

int main() {
    scanf("%d%c", &query, &c);
    while (c !='\n')
        scanf("%d%c", &arr[arr_size++], &c);
    switch(query) {
    case 0:
        printf("%d", index_first_even(arr, arr_size));
        break;
    case 1:
        printf("%d", index_last_odd(arr, arr_size));
        break;
    case 2:
        printf("%d", sum_between_even_odd(arr, arr_size));
        break;
    case 3:
        printf("%d", sum_before_even_and_after_odd(arr, arr_size));
        break;
    default:
        printf("Данные некорректны");
    }
    return 0;
}