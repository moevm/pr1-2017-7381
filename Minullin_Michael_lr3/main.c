
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char* text;
    int text_len = 1;
    text = calloc(text_len, sizeof(char));
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            continue;
        ++text_len;
        text = realloc(text, text_len * sizeof(char));
        text[text_len - 2] = c;
    }
    text[text_len - 1] = '\0';
    int n = 0;
    int m = 0;
    int l = 0;
    int r = 0;
    for (; r < text_len; ++r) {
        c = text[r];
        if (c == '.' || c == ';' || c == '!') {
            ++n;
            ++m;
            int str_len = r - l + 1;
            char* str = malloc((str_len + 1) * sizeof(char));
            strncpy(str, text + l, str_len);
            str[str_len] = '\0';
            int i = 0;
            while (str[i] == '\t' || str[i] == ' ')
                i++;
            puts(str + i);
            free(str);
            l = r + 1;
        }
        if (c == '?') {
            ++n;
            l = r + 1;
        }
    }
    printf("Количество предложений до %d и количество предложений после %d", n - 1, m - 1);
    free(text);
    return 0;
}
