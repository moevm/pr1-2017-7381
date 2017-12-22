#include <stdio.h>
#include <stdlib.h>

#define N 15

int main(){
    int i=0, k=0, per=0,current=0, l=0, m;
    char c;
    char *str1=(char*)calloc(N, sizeof(char));
    while((c=getchar())!='!')
    {   if(c=='\t'||c=='\n')
           continue;
        if(i%N==0 && i>0)
            str1=(char*)realloc(str1, (i+N+2)*sizeof(char));
        str1[i]=c;
        if(str1[i]=='.'||str1[i]==';'||str1[i]=='?')
            k++;
        i++;
    }
    str1[i++]='!';
    str1[i]='\0';
    i=0;
    for(m=0;m<=k;m++)
    {
        for(current=i;str1[i]!='.' && str1[i]!=';' && str1[i]!='!' && str1[i]!='?';i++);
        if(str1[i]!='?')
        {
            per=i;
            for(i=current;str1[i]==' ';i++);
            for(;i<=per;i++)
              printf("%c", str1[i]);
            printf("\n");
            l++;
        }
        i++;
    }
    printf("Количество предложений до %d и количество предложений после %d\n", k, l-1);
    free(str1);
    return 0;
    }
