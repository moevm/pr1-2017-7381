#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
	#define NUM 50
	int i = 0, k = 0, m = 0, n = 0;
	char c;
	char* text = NULL;
	
		do {
		text = (char* ) realloc(text, (i+1)*sizeof(char));
		text[i] = getchar();
		if (text[i] == ';' || text[i] == '?' || text[i] == '.')
		n++;
		i++;
		}
		while (text[i-1] != '!');
	
	int s_begin, w_begin, main_flag, j, z;
	int flag [2];

	for (i = 0, k = 0; k <= n; k++) 
	{
		for (main_flag = 0, s_begin = i; text[i] != '?' && text[i] != ';' && text[i] != '.' && text[i] != '!' ;)
		{
			for(z = 0; z < 2; flag [z++] = 0);

			if (isdigit(text[i]))
    			flag [0] = 1;

			for (z = 0, w_begin = i; text[i] != ' ' && text[i] != '?' && text[i] != ';' && text[i] != '.' && text[i] != '!' ; i++){
				if (text[i+1] != ' ' && text[i+1] != '?' && text[i+1] != ';' && text[i+1] != '.' && text[i+1] != '!') 
				{
	    			if (isdigit(text[i]) && !isdigit(text[i+1]))
						z++;
	    			if (z > 1)
	    				{
	        			main_flag = 1;
	        			break;
	    				}
	    			if (!isdigit(text[i]) && isdigit(text[i+1]))
	 		   			flag[z] = 1;
				}
				
			}
			if (z == 1 && flag [z] == 0 && !isdigit(text[w_begin]) && !isdigit(text[i-1])){
				main_flag = 1;
				break;
			}
			if (z == 1 && flag [z] == 1 && !isdigit(text[w_begin])){
				main_flag = 1;
				break;
			}		
			if (text[i] == ' ')
				i++;
		}
		if (!main_flag){
			for (j = s_begin; isspace(text[j]); j++);
			do {
				putchar(text[j]);
			}
			while (text[j] != '?' && text[j] != ';' && text[j] != '.' && text[j++] != '!');
			putchar('\n');
			m++;
			}
		while (text[i] != '?' && text[i] != ';' && text[i] != '.' && text[i++] != '!')
                ;
		i++;
	}

	printf("Количество предложений до %d и количество предложений после %d\n", n, m-1); 

	free(text);
}