
#include "index_first_zero.h"
#include "index_last_zero.h"
#include "sum_between.h"
#include "sum_before_and_after.h"

#include <stdio.h>

int arr[100];
int arr_size = 0;
int query;
int value;
int c;

int main() {
    scanf("%d", &query);
    while ((c = getc(stdin)) != '\n') {
        ungetc(c, stdin);
        scanf("%d", &value);
        arr[arr_size++] = value;
    }
    switch (query) {
    case 0:
        printf("%d", index_first_zero(arr, arr_size));
        break;
    case 1:
        printf("%d", index_last_zero(arr, arr_size));
        break;
    case 2:
        printf("%d", sum_between(arr, arr_size));
        break;
    case 3:
        printf("%d", sum_before_and_after(arr, arr_size));
        break;
    default:
        printf("Данные некорректны");
    }
    return 0;
}
