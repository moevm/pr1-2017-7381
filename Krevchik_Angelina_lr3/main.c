#include <stdio.h>
#include <stdlib.h>

int main() {
 int i=-1,m=0,n=0,p,index,l;
 char* s=NULL;
do {
	i++;

	s=(char* )realloc(s,i+1);
    s[i]=getchar();
       
     if (s[i]=='.' || s[i]==';' || s[i]=='?')
        n++;
 
}

while(s[i]!='!');


for(p=0, i=0;p<=n;p++)
{
	for(index=i;s[i]!='.' && s[i]!=';' && s[i]!='?' && s[i]!='!';i++);
    if(s[i]!='?'){
    	l=i;
    for(i=index;s[i]==' ' || s[i]=='\t';i++);
    

    for(;i<=l;i++)
    putchar(s[i]); 
    putchar('\n');
    m++;



}
i++;
    	
}

printf("Количество предложений до %d и количество предложений после %d\n", n, m-1);
free (s);

  return 0;
}