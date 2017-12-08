#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char c;
    char *text = calloc(200, sizeof(char));
    int text_size = 0;
    while ((c = getchar()) != '!') {
         if (c=='\n' || c=='\t')
             continue;
         if (text_size%200==0 && text_size>0)
             text = realloc(text, (text_size+200)*sizeof(char));
         text[text_size] = c;
         text_size++;
    }
    if (text_size%200==0)
             text = realloc(text, (text_size+200)*sizeof(char));
    text[text_size]='!';
    text_size++;
    
    // в text хранится оригинальный текст без табуляций и переносов строк
    
    
    int i, j, proverka, n=0, m=0, start=0, end;
    
    while (1){
        for (j=start;;j++){
            if (text[j]=='.' || text[j]==';' || text[j]=='?' || text[j]=='!'){
                end = j;
                n++;
                break;
            }
        } // нашел границы предложения
        
        for (j=start+1, proverka = 1; j<=end; j++){
            if ( isdigit(text[j]) && !isspace(text[j-1]) && !isspace(text[j+1]) && !isdigit(text[j-1]) && text[j+1]!='.' && text[j+1]!=';' && text[j+1]!='!' && text[j+1]!='?' ){
                while (isdigit(text[j]))
                    j++;
                if (!isspace(text[j]) && text[j]!='.' && text[j]!=';' && text[j]!='?' && text[j]!='!'){
                    proverka = 0;
                    break;
                }
            }
        } // проверел, есть ли цифры в словах этого предложения
        
        if (proverka){
            for (j=start; j<=end; j++)
                printf("%c", text[j]);
            printf("\n");
            m++;
        } // если цифр нет, вывел это предложение и перенес строку
        
        if (text[end]=='!')
            break; // если это было последнее предложение, прерываю цикл
        
        start=end+1;
        while (1)
            if (isspace(text[start]))
                start++;
            else
                break; // перешел к следующему предложению
    }
    
    n--;
    m--;
    printf("Количество предложений до %d и количество предложений после %d",n,m);
    free (text);
    return 0;
}