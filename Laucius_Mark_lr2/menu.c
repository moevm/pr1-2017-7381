#define N 100
#include "index_first_zero.h"
#include "index_last_zero.h"
#include "sum_between.h"
#include "sum_before_and_after.h"
#include <stdio.h>
int read(int* mass){
    int c, size=0;
    while ((c = getc(stdin)) != '\n' && size<N) {
        ungetc(c, stdin);
        scanf("%d", &mass[size++]);
    }    
    return size;
}
int main() {
    int mass[N];
    int size;
    int val;
    scanf("%d", &val);
    size=read(mass);
    switch (val) {
    case 0:
        printf("%d", index_first_zero(mass, size));
        break;
    case 1:
        printf("%d", index_last_zero(mass, size));
        break;
    case 2:
        printf("%d", sum_between(mass, size));
        break;
    case 3:
        printf("%d", sum_before_and_after(mass, size));
        break;
    default:
        printf("Данные некорректны");
    }
    printf("\n");
    return 0;
}
