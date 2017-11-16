#include "get_name.h"

char* get_name(){
	char* name=(char*)malloc(80*sizeof(char));
	char ch;
	int i=0;
	while((ch=getchar())!='\n){
		name[i] = ch;
		i++;
	}
	name[i] = '\0';
	return name;
} 
