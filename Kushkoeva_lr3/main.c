#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
int h=0;
int i=1;
int m=0;
int k=0;//количество предложений до обработки
int p=0;//после обработки
char* text=malloc(i*sizeof(char));
char c=getchar();
while(c!='!')
{
text[i-1]=c;
c=getchar();
text=(char*)realloc(text, (++i) *sizeof(char));
}
text[i-1]='!';
text[i]='\0';
char* text2=malloc(1 * sizeof(char));
i=0;
while(text[i]!='!')
{
        while(text[i]=='\t' || text[i]==' ')
        i++;

        while(text[i]!='.' && text[i]!=';' && text[i]!='?'  && text[i]!='!')
        {
        text2[m]=text[i];
        text2=realloc(text2, ((++m)+1) * sizeof(char));
        i++;
             ++h;
        }

        if(text[i]=='.' || text[i]==';')
             {
        text2[m]=text[i];
        text2=realloc(text2, ((++m)+1) * sizeof(char));
        i++;
        text2[m]='\n';
        text2=realloc(text2, ((++m)+1) * sizeof(char));
        k++;
        p++;
        h=0;
        }
    
        if(text[i]=='?')
        {
        k++;
        i++;
        m=m-h;
        h=0;
        }
}
text2[m]='!';
text2=realloc(text2, ((++m)+1) * sizeof(char));
text2[m]='\0';
printf("%s\n", text2);
printf("Количество предложений до %d и количество предложений после %d", k, p);
    free(text);
    free(text2);
return 0;
}
