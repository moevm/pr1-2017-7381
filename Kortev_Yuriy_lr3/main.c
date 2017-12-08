#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i;
    int n=0;
    int m=0;
    char c;
    int d=1;
   
 char* text_out;
  char* text=(char*)malloc(30*sizeof(char));
    while(c=getchar()!='!')
    {
        if(c=='.' || c==';' || c=='?')//кол-во предложений
        {
            n++;
        }
        if(i==(30*d))
        {
            text=realloc(text, 30*(d++)*sizeof(char));
        }
        text[i]=c;
        i++;
    }
    text[i]='!';
    text[i++]='\0';
    //фильтр
    for(i=0;i<=n;i++)
    {
        while(*text!='.'|| *text!=';' || *text!='?')
        {
            text_out=malloc((strlen(text)+1)*sizeof(char));
            if(*text=='\t')
            {
                text++;
            }
            if((*text_out=*text)==5 & (*(text_out++)=*(text++))==5 & (*(text_out++)=*(text++))==5)
            {
                m++;
                break;
            }
        text++;
            text_out++;
            *text_out=*text;
        }
                *text_out=*text;
        printf("%s\n", text_out);
        free(text_out);
    }
    
free(text);
   
    printf("Количество предложений до %d и количество предложений после %d", n, n-m);
        
    
    
  return 0;
}
