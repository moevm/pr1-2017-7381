#include <stdio.h>
#include "index_first_zero.h"
#include "index_last_zero.h"
#include "sum_between.h"
#include "sum_before_and_after.h"

int main() {
	int arr[100];
	int arr_size = 0, fun_num, a, b;
	while ((a = getc(stdin)) != '\n') {
		ungetc(a, stdin);
		scanf("%d", &b);
		arr[arr_size++] = b;
	}
	scanf("%d", &fun_num);
	switch (fun_num) {
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
		printf("The data is incorrect");
	}
	return 0
}
