#define STR "Dragon flew away!" 
#define CH "555" 
#define SIZE 50
#define PLUSSIZE 50
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h>
int main() { 
    int n=0, i=0, m=0, k=0; 
    char c; 
    do{ 
        i=0; 
        char* string =(char*)calloc(SIZE, sizeof(char)); 
        do{ 
            do{ 
                c = getc(stdin); 
            }while((c==' '||c=='\t')&&!i); 
            string[i++]=c; 
            //i++; 
            if(!((i-SIZE+1)%PLUSSIZE))
                string=(char*)realloc(string, i+PLUSSIZE);         }while(c!='.'&&c!=';'&&c!='?'&&!strstr(string,STR)); 
        n++;        
        string[i]='\0';
        char* a=strstr(string,CH);     if(!(a&&!isalpha(*(a-1))&&!isalpha(*(a+3))&&!isdigit(*(a-1))&&!isdigit(*(a+3)))){ 
            printf("%s\n", string);
            m++; 
        } 
        if(strstr(string,STR))
            k=1; 
        free(string); 
    }while(!k); 
    printf("Количество предложений до %d и количество предложений после %d\n", n-1, m-1); 
    return 0; 
}
