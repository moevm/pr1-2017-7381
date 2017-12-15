#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int i=0;
    int len=1;   
   char* sentence=calloc(len, sizeof(char));
    int len2=1;
    char c,a;
    while((c=getchar())!=EOF)
    {
        ++len;
        sentence=realloc(sentence, len*sizeof(char));
        sentence[len-2]=c;
    }
sentence[len-1]='\0';
    char* sentence2=calloc(len2, sizeof(char));
    int m=0,n=0,k=0;
    
   int Up=0; //кол-во звглавных букв
    
    for (i=0;i<strlen(sentence);++i){
        a=sentence[i];
        sentence2[k]=a;
		if((sentence2[0]==' ')||(sentence2[0]=='\t')){
			++i;
			a=sentence[i];
			sentence2[0]=a;
			
		}
        ++k;
	++len2;
	sentence2=(char*)realloc(sentence2,len2*sizeof(char));
        if(isupper(a)){++Up;}
        if ((a == '.') || (a == ';') || (a == '?') || (a== '!')){
            ++m;
            ++n;
	
            if(Up<=1){
	sentence2[k]='\0';
        printf("%s\n",sentence2);}
            else{--m;}
	Up=0;
	k=0;
	len2=1;
	sentence2=(char*)realloc(sentence2,len2*sizeof(char));
        }
}
            printf("Количество предложений до %d и количество предложений после %d ",n-1,m-1);
free(sentence);
free(sentence2);
return 0;
}

