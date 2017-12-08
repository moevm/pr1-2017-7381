#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 16
#define term "Dragon flew away!"

int main(){
 char* sen = (char*)calloc(1,sizeof(char));
  int s = 0;
   int n = 0, m = 0;
    char c;
   while(strcmp(sen,term)){
        c = getchar();
        if((s==0) && ((c=='\t') || (c==' ')))
	continue;
        if ((s % N) == 0)
         sen = (char*)realloc(sen, (strlen(sen)+N+1)*sizeof(char));
        sen[s++] = c;
        if ((c == '.') || (c == ';')){
         sen[s]='\0';
          printf("%s\n", sen);
           free(sen);
            sen = (char*)calloc(1,sizeof(char));
           n++;
          m++;
         s = 0;
        }
    if (c=='?'){
        n++;
         s = 0;
         free(sen);
        sen = (char*)calloc(1,sizeof(char));
    }
  }
 printf("%s\n", sen);
 printf("Количество предложений до %d и количество предложений после %d", n, m);
 free(sen);
return 0;
}
