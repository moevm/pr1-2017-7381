#include <stdio.h>
#include <stdlib.h>

int check_word(char*word, int len) {
	int i;
	int l=0, r=len-1;
	while (word[l] >= '0' && word[l] <= '9' && l < len) {
		l++;
	}
	if (l >= len-1)
		return 1;
	while (word[r] >= '0' && word[r] <= '9' && r >= 0) {
		r--;
	}
	if (r <= 0)
		return 1;
	for (i = l; i <= r; i++) {
		if (word[i] >= '0' && word[i] <= '9') {
			return 0;
		}
	}
	return 1;
}

int main() {
    int before=0;
	char*str = (char*)malloc(100*sizeof(char));
	char**text = NULL;
	int i,l, line,linepos;
	int w = 0;
	int end = 0;

// 	FILE* inputFile = fopen("input.txt", "r");
	int res = 0;

	line = 0;
	linepos = 0;
	while ((res = scanf("%[^ .;?\n\t]",str)) != EOF) {
		l = 0;
		if (res != 0) {
			while (str[l] != '\0') {
				l++;
			}
			w=check_word(str, l);
			if (w == 0) {
				scanf("%[^.;?]", str);
				scanf("%c", str);
				before++;
				linepos = 0;
				continue;
			}
			if (linepos == 0) {
				text = realloc(text, (line + 1) * sizeof(char*));
				text[line] = NULL;
			}
			text[line] = realloc(text[line], (linepos + l) * sizeof(char));
			for (i = 0; i < l; i++) {
				text[line][linepos+i] = str[i];
			}
			linepos += l;
		}
		scanf("%c", str);
		switch (str[0]) {
		case '!':
			end = 1;
			break;
		case '\t':
		case ' ':
			if (linepos != 0) {
				text[line] = realloc(text[line], (linepos + 1) * sizeof(char));
				text[line][linepos] = str[0];
				linepos++;
			}
			break;
		case '.':
		case ';':
		case '?':
			text[line] = realloc(text[line], (linepos + 2) * sizeof(char));
			text[line][linepos] = str[0];
			text[line][linepos+1] = '\0';
			line++;
			linepos = 0;
			before++;
			break;
		case '\n':
			if (linepos != 0) {
				text[line] = realloc(text[line], (linepos + 1) * sizeof(char));
				text[line][linepos] = ' ';
				linepos++;
			}
				break;
		default:
			if (linepos != 0) {
				text[line] = realloc(text[line], (linepos + 1) * sizeof(char));
				text[line][linepos] = str[0];
				linepos++;
				break;
			}
		}
	}

	for (i = 0; i < line; i++) {
		printf("%s\n", text[i]);
	}
	printf("Dragon flew away!\n");

    printf("Количество предложений до %i и количество предложений после %i\n",before,line);
	return 0;
}

