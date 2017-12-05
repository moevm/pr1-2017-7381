#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    int i=0, d=1;
    char c;
    char *text1=malloc(101*sizeof(char));
    while ((c=getchar()) != '!')
    {
        text1[i++]=c;
        if ((i%100)==0)
        {
            text1=realloc(text1,100*sizeof(char)*(++d)+sizeof(char));
        }
    }
    text1[i++]='!';
    text1[i]='\0';
    i=0;


    int bil_probel, t, b, n=0, m=0;
    char *text2 = malloc(strlen(text1)*sizeof(char));
    char *text2_start = text2;
    while(text1[i]!='\0')
    {
        n++;
        b = t = bil_probel = 0;
        while ((text1[i]!=';') && (text1[i]!='.') && (text1[i] != '?') && (text1[i] != '!'))
        {
            if ((!isspace(text1[i])) || (bil_probel))
                {
                    text2[t++]=text1[i];
                    if (!bil_probel)
                        bil_probel = 1;
                }
            i++;
        }
        text2[t++]=text1[i++];
        text2[t]='\0';
        for(t = 1; t < strlen(text2); t++)
            if (isdigit(text2[t]) && !isdigit(text2[t-1]) && !isspace(text2[t-1]) && !isspace(text2[t+1]) && !(text2[t+1]=='!') && !(text2[t+1]==';') && !(text2[t+1]=='.') && !(text2[t+1]=='?'))
            {
                while(isdigit(text2[t]))
                    t++;
                if (!isspace(text2[t]) && !(text2[t]=='!') && !(text2[t]==';') && !(text2[t]=='.') && !(text2[t]=='?'))
                    {
                        b=1;
                        break;
                    }
            }

        if (!b)
        {
            printf("%s\n",text2);
            m++;
        }

        text2 = text2_start;
    }
    printf("Количество предложений до %d и количество предложений после %d\n",n-1,m-1);
    free(text1);
    free(text2);
    return 0;
}