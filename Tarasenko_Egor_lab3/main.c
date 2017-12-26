#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 1000

char** text;
int* index_del;
int count_str = 0;
int deleted_str = 0;
int i, j, n = 0, flag = 0;
char a;

int main()
{
	text = (char**)malloc(N*sizeof(char*));
	for(i=0; i<N; i++) text[i] = (char*)malloc(N*sizeof(char));
	index_del = (int*)malloc(N*sizeof(int));

	i = 0;
	for(int k; k<(N*N); k++)
	{
		a = getchar();
		if ((a == ' ' && i == 0) || a == '\t' || a == '\n')
			continue;
		text[count_str][i] = a;

		if(text[count_str][i] == '.'){
			text[count_str][i+1] = '\n';
			count_str++;
			i = 0;
			continue;
		}
		if(text[count_str][i] == ';'){
                        text[count_str][i+1] = '\n';
			count_str++;
			i = 0;
			continue;
		}
		if(text[count_str][i] == '?'){
                        text[count_str][i+1] = '\n';
			count_str++;
			i = 0;
			continue;
		}
                if(text[count_str][i] == '!'){
                        text[count_str][i+1] = '\n';
                        count_str++;
                        i = 0;
			break;
                }
		i++;
	}
//enter the text, delete tabs and enter each sentense to a new line;

	for(i=0; i<count_str; i++)
	{
		n = 0;
		for(j=0; j<strlen(text[i]); j++)
		{
			if(isupper(text[i][j])) n++;
//			if(text[i][j] == ' ') n = 0;
		}
		if(n > 1){
			index_del[deleted_str] = i;
			deleted_str++;
		}
	}
//delete sentenses, which have one more upper litters;

	for(i=0; i<count_str; i++)
	{
		flag = 0;
		for(n=0; n<deleted_str; n++) if(i == index_del[n]) flag = 1;
		if(flag == 0) for(j=0; j<strlen(text[i]); j++) printf("%c", text[i][j]);
	}
	printf("Before: %d, after: %d.\n", count_str-1, count_str-deleted_str-1);
//print the text;

	for(i=0; i<N; i++) free(text[i]);
	free(text);
	free(index_del);
	return 0;
}

