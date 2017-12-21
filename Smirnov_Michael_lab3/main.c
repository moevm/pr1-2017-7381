#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
#include <ctype.h>


int prove(char* s, int i);

int main()
{
    char* text; char c = 'x'; int i=0; int len=100;
    char* rezt; char* tp;char* ltext;

    text=(char*)malloc(len*sizeof(char));

while(c!= '!' ){
c=getchar();
text[i] = c;
i++;
if(i == len){
len = len +len;
text = (char*)realloc(text, len*sizeof(char));
}
}

text[i+1]='\0';

int fire=0; int che;
for(che=0;che<strlen(text);che++)
{
    if (text[che]==';' || text[che]=='.' || text[che]=='?')
        fire=fire+1;
}
int pen;


for(pen=0;pen<strlen(text);pen++)
{
    if (text[pen]=='\t')
        text[pen]=' ';
}
ltext=(char*)malloc(strlen(text)*sizeof(char));
int j=0;
int k;
for (k=0; k<strlen(text);k++){
if (text[k]==' ')
{
    if (j==0) continue;
    if (text[k+1]==' ') continue;
}
    ltext[j]=text[k];
    j++;
}

int hel;
//перенос строки

for(hel=0;hel<strlen(ltext);hel++)
{
   if (ltext[hel]==';' || ltext[hel]=='.' || ltext[hel]=='!' || ltext[hel]=='?')
    ltext[hel+1] = '\n';

}

int a=0, b, f=0, g=0;
rezt=(char*)malloc(strlen(ltext)*sizeof(char));
    while(ltext[a]!='!')
   {
   b=0;
   tp=(char*)malloc(len*sizeof(char));
   do {
        tp[b]=ltext[a];
        b++;
        a++;
      }while(ltext[a]!='\n'&&ltext[a]!='!');

        if (prove(tp, b)==1)
                for(f=0;f<b;g++,f++)
                rezt[g]=tp[f];
    free(tp);
   }

rezt[g]='!';

        if (rezt[0]=='\n')
        {
            for(a=1;rezt[a]!='!';a++)
            printf("%c",rezt[a]);
        }
           else
            if (rezt[0]==' ')
            {
            for(a=1;rezt[a]!='!';a++)
            printf("%c",rezt[a]);
            }
               else for(a=0;rezt[a]!='!';a++)
                printf("%c",rezt[a]);

printf("!\n");

int mm=0; int ff;
for(ff=0;rezt[ff]!='!';ff++)
{
    if (rezt[ff]==';' || rezt[ff]=='.' || rezt[ff]=='?')
        mm=mm+1;
}
printf("Количество предложений до %d и количество предложений после %d\n",(fire),(mm));
free(text);
free(ltext);
free(rezt);
 return 0;
}


int prove(char* s, int i)
{
    int a;char sw[i]; int b;int c;int d;
    for (a=0;a<i;a++)
    {
        d=a;
        if (d==' ') d++;
        b=0;
        while(isalnum(s[d]))
        {sw[b]=s[d];
        b++;
        d++;
        }
        for(c=1;c<b;c++)
        {if(isdigit(sw[0])||isdigit(sw[b-1]))continue;
            if (isdigit(sw[c]) && isalnum(sw[c-1]) && isalnum(sw[c+1]))
            return 0;
        }

    }
   return 1;
}
