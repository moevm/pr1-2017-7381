#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 


int pr_str(char *str, int current){ 
int true=1; 
if (str[current-1]=='?'){ 
    true = 0;

} 



if (true){ 
for (int i=0;i<current;i++){ 
printf("%c", str[i]); 
} 
printf("\n"); 
return 1; 
} 
return 0; 
} 


int main(){ 
int i=0;
int k=0; 
int length=0; 
char n=0; 
int current=0; 
int before=0; 
int after=0; 
int flag=1; 
char *str = malloc(1* sizeof (char)); 

while ((n=getchar()) != '\n' ){
str = realloc(str,sizeof(char*)*(k+2));
k++;    
if (flag){ 
if (n==' ' || n=='\t'){ 
continue; 
} 
flag=0; 
} 

length=current; 
*(str+length)=n; 
current=current+1; 
if (n=='.' || n==';' || n=='?' || n=='!'){ 
after=after + pr_str(str, current); 
i++;
current=0; 
flag=1; 
before++; 
} 

} 

printf ("Количество предложений до %d и количество предложений после %d",(before-1), (after-1)); 

free (str); 

return 0; 
}
