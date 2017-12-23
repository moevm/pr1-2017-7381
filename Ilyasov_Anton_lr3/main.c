#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 5000

int print_str(char *str, int pos) {

	int true = 1;
	if (str[pos-1] == '?') {
		true = 0;
	}

	if (true) {
		for (int i = 0; i < pos; i++) {
			printf("%c", str[i]);
		}
		printf("\n");
		return 1;
	}
return 0;
}

int main() {

	int i = 0;
	int t = 0;
	int len;
	char c;
	int pos = 0;
	int n = 0;
	int m = 0;
	int flag = 1;
	char *str = malloc(N*sizeof(char));

	while ((c = getchar()) != '\n') {
		if (flag) {
			if (c == ' ' || c == '\t') {
				continue;
			}
			flag = 0;
		}

		len = pos;
		str[len] = c;
		pos++;
		if (c == '.' || c == ';' || c == '?') {
			m = m + print_str(str, pos);
			pos = 0;
			flag = 1;
			n++;
		}
	}

	printf ("Количество предложений до %d и количество предложений после %d\n", n, m);
	free (str);
return 0;
}
