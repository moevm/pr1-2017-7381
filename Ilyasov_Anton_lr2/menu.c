#include <stdio.h>
#include "max.h"
#include "min.h"
#include "diff.h"
#include "sum.h"

int main() {

	int i=0;
	int n , result;
	char c;
	int mas[100];
	scanf("%d%c", &n, &c);
	scanf("%d%c", &mas[0], &c);
	while (c!='\n') {
		i++;
		scanf("%d%c", &mas[i], &c);
	}
	i++;
	result = 0;
	switch(n){
		case 0: result = max(mas, i);
            printf("%d\n", result );
            break;
		case 1: result = min(mas, i);
            printf("%d\n", result);
            break;
		case 2: result = diff(mas, i);
            printf("%d\n", result);
            break;
		case 3: result = sum(mas ,i);
            printf("%d\n", result);
            break;
		default: printf("Данные некоректны\n");
	}
}

