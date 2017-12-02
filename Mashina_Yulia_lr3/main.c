#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 60
int main()
{
    int i=0, q=0, b=1, n=0, m=0, flag = 0, print_flag = 0; char a;
    char *text = (char*)calloc((N+1), sizeof(char));
    while (flag != 3)
    {
        if (((i+2) % N) == 0)
        {
            text = realloc(text,N*sizeof(char)*(++b)+sizeof(char));
        }
        a = getchar();
        if (!isspace(a) && flag == 0) // перед предложением не было пробелов
        {
            text[i++] = a; flag = 2;// flag 2 значит теперь не игнорировать пробелы
        }
        else if (flag == 2) //  flag 2 - не игнорировать пробелы
        text[i++] = a;
        else if (!isspace(a) && flag == 1) // перед предложением был пробел, а теперь не пробел, записать и больше не игнорировать пробелы
        {
            text[i++] = a; flag = 2; // теперь не игнорировать пробелы
        }
        else
        {
            flag = 1; continue; // перед предложением был пробел, игнорировать его
        }
        if ((a == '.') || (a == ';') || (a == '?'))
        {
            for(q = 1; q < strlen(text); q++)
            if (isdigit(text[q]) && !isdigit(text[q-1]) && !isspace(text[q-1]) && !isspace(text[q+1]) && !(text[q+1]=='!') && !(text[q+1]==';') && !(text[q+1]=='.') && !(text[q+1]=='?'))
            {
                while(isdigit(text[q]))
                    q++;
                if (!isspace(text[q]) && !(text[q]=='!') && !(text[q]==';') && !(text[q]=='.') && !(text[q]=='?'))
                    {
                        print_flag=1;
                        break;
                    }
            }
            if (print_flag!=1)
            {
                text[i]='\0'; printf("%s\n", text); n++; m++;
                free(text);
                text = (char*)calloc((N+1), sizeof(char)); i=0; flag = 0;
            }
            else
            {
                i = 0; b = 1; flag = 0; print_flag = 0; free(text);
                text = (char*)calloc((N+1), sizeof(char)); n++;
            }
        }
        if (a == '!')
        {
            text[i]='\0'; printf("%s\n", text); flag = 3; 
            printf("Количество предложений до %d и количество предложений после %d\n", n, m); 
        }
    }
free(text);
return 0;
}