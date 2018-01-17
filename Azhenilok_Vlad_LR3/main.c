#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int i=0;
    int len=1;   
   char* sentence=calloc(len, sizeof(char));
    int len1=1;
    char a,b;
    while((b=getchar())!=EOF)
    {
        ++len;
        sentence=realloc(sentence, len*sizeof(char));
        sentence[len-2]=b;
    }
sentence[len-1]='\0';
    char* sentence2=calloc(len1, sizeof(char));
    int m=0,n=0,k=0;
    
   int Up=0;
    
    for (i=0;i<strlen(sentence);++i){
        a=sentence[i];
        sentence1[k]=a;
		if((sentence1[0]==' ')||(sentence1[0]=='\t')){
			++i;
			a=sentence[i];
			sentence1[0]=a;	
		}
        ++k;
	++len1;
	sentence1=(char*)realloc(sentence1,len1*sizeof(char));
        if(isupper(a)){++Up;}
        if ((a == '.') || (a == ';') || (a == '?') || (a== '!')){
            ++m;
            ++n;	
        if(Up<=1){
	sentence1[k]='\0';
        printf("%s\n",sentence1);}
            else{--m;}
	Up=0;
	k=0;
	len1=1;
	sentence1=(char*)realloc(sentence1,len1*sizeof(char));
        }
}
            printf("Количество предложений до %d и количество предложений после %d ",n-1,m-1);
free(sentence);
free(sentence1);
return 0;
}
