#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char c;
    char *text = calloc(50, sizeof(char));
    int text_size = 0;
    while ((c = getchar()) != '!') {
         if (c=='\n' || c=='\t')
             continue;
         if (text_size%50==0 && text_size>0)
             text = realloc(text, (text_size+50)*sizeof(char));
         text[text_size] = c;
         text_size++;
    				   }
    if (text_size%50==0)
             text = realloc(text, (text_size+50)*sizeof(char));
    text[text_size]='!';
    text_size++;

 //text - оригинальный текст без табуляций и переносов строк


    int i, k, proverka, n=0, m=0, nachalo=0, konetc;

    while (1){                                                                                         //бесконечный цикл, если истинна
        for (k=nachalo;;k++){
            if (text[k]==';' || text[k]=='.' || text[k]=='?' || text[k]=='!'){
                konetc = k;
                n++;
                break;
	          							    }
            		  }
 // нашла границы предложения, количество предложений изначально

        for (k=nachalo+1, proverka = 1; k<=konetc; k++){
            if ( isdigit(text[k]) && !isspace(text[k-1]) && !isspace(text[k+1]) && !isdigit(text[k-1]) && text[k+1]!=';' && text[k+1]!='.' && text[k+1]!='!' && text[k+1]!='?' )
						  {
//isdigit - возвращает ненулевое значение, если десятичное число
//isspace - возвращает true, если пробельный символ

  while (isdigit(text[k]))
                    k++;
                if (!isspace(text[k]) && text[k]!='!' && text[k]!=';' && text[k]!='?' && text[k]!='.')
		{
                    proverka = 0;
                    break;
                }
           					  }
       						  }
// проверела, есть ли цифры в словах этого предложения

        if (proverka){
            for (k=nachalo; k<=konetc; k++)
                printf("%c", text[k]);
            printf("\n");
            m++;
       		    }
// если цифр нет, вывела предложение и перенесла строку, увеличила предложения после

        if (text[konetc]=='!')
            break;
// если это последнее предложение, прерываю цикл

        nachalo=konetc+1;
        while (1)
            if (isspace(text[nachalo]))
                nachalo++;
            else
                break;
// перешла к следующему предложению
    }
    n--;
    m--;
    printf("Количество предложений до %d и количество предложений после %d",n,m);
    free (text);
    return 0;
}
