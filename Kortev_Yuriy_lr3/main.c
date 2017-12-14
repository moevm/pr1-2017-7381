#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i;
    int n=0;
    int m=0;
    char c;
    int d=1;
    int f=0;
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
            d++;
            text=realloc(text, (30*d)*sizeof(char));
        }
        text[i]=c;
        i++;
    }
    text[i]='!';
    text[i++]='\0';
    //фильтр
    char *print_out;
    for(i=0;i<n;i++)
    {
        text_out=malloc((strlen(text)+1)*sizeof(char));
        while(*text!='.'|| *text!=';' || *text!='?')
        {
            print_out=text_out;
            if(*text=='\t')
            {
                text++;
            }
            if((f==1||f==2)&*text!='5')
            {
                f=0;
            }
            if(*text=='5')
            {
                f++;
            }
            if(f==3)
            {
                m++;
                break;
            }
            
            *text_out=*text;
            text++;
            text_out++;
        }
                *text_out=*text;
        printf("%s\n", print_out);
        free(text_out);
        free(print_out);
        text++;
    }
    
free(text);
   
    printf("Количество предложений до %d и количество предложений после %d", n, n-m);
        
    
    
  return 0;
}
