#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "header.h"
#include "reverse.h"
 
int main(){
	int length;
	printf("Создание списка композиций.\nВведите количество композиций:");
	scanf("%d", &length);  
	char** names = (char**)malloc(sizeof(char*)*length);
	char** authors = (char**)malloc(sizeof(char*)*length);
	int* years = (int*)malloc(sizeof(int)*length);
	//char** years = (char**)malloc(sizeof(char*)*length);
	int i;
	for (i=0;i<length;i++)
	{
	        char name[80];
	        char author[80];
		//char year[10]
		printf("Введите название композиции (не больше 80 символов):");
		getchar();
		fgets(name, 80, stdin);
	        printf("Введите имя автора композиции (не больше 80 символов):");
		getchar();
		fgets(author, 80, stdin);
	        printf("Введите год создания композиции:");
	        fscanf(stdin, "%d", &years[i]);
		//fgets(year, 10, stdin);
	
	        (*strstr(name,"\n"))=0;
	        (*strstr(author,"\n"))=0;
		//(*strstr(year,"\n"))=0;
	
	        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
	        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
		//years[i] = (char*)malloc(sizeof(char*) * (strlen(year)+1));
	        strcpy(names[i], name);
	        strcpy(authors[i], author);
		//strcpy(years[i], year);

	}
	MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
	
	if(names!=NULL)
	free(names);
	if(authors!=NULL)
	free(authors);
	if(years!=NULL)
	free(years);
	


	
	char name_for_remove[80];
	int what_you_want=0;
	printf("1 - добавить композицию.\n");
	printf("2 - удалить композицию(-и) по имени.\n");
	printf("3 - вывести на экран количество компазиций.\n");
	printf("4 - вывести на экран названия компазиций.\n");
	printf("5 - поменять местами 1й и nй, 2й и n-1 элементы списка.\n");
	printf("6 - завершить работу программы.\n");
	int k=0;
	getchar();
	char *name_for_push=NULL;
	char *author_for_push=NULL;
	int year_for_push;
	while(what_you_want!=6)
	{       
		printf("Выберете действие которое хотите совершить:");
		scanf("%d",&what_you_want);
                if(!((int)what_you_want >= 1 && (int)what_you_want <= 6)){
			printf("wrong\n");
			getc(stdin);
			continue;
		}
		switch(what_you_want)
		{
		case 1: 
			author_for_push = (char*)malloc(sizeof(char*) * 80);
			name_for_push = (char*)malloc(sizeof(char*) * 80);
		        printf("Введите название композиции (не больше 80 символов):");
			getchar();
        	        fgets(name_for_push, 80, stdin);
        	        printf("Введите имя автора композиции (не больше 80 символов):");
			getchar();
        	        fgets(author_for_push, 80, stdin);
        	        printf("Введите год создания композиции:");
    			fscanf(stdin, "%d", &year_for_push);
    			(*strstr(name_for_push,"\n"))=0;
    			(*strstr(author_for_push,"\n"))=0;
			MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
			push(&head, element_for_push);
		break;
		case 2: 
			printf("Введите название композиции:");
			getchar();
			fgets(name_for_remove, 80, stdin);
    			(*strstr(name_for_remove,"\n"))='\0';
	    		removeEl(&head, name_for_remove);
		break;
  		case 3:
         		k = count(head);
			printf("Количество компазиций:%d\n", k);
			getchar();
		break;
		case 4:
			print_names(head);
			getchar();
		break;
		case 5:
			reverse(&head);
			getchar();
		break;
		}
	}
	if(head!=NULL){
		while(head->next)
		{
			head=head->next;
			free(head->previous);
			head->previous=NULL;
		}
		if(head!=NULL)
		free(head);
		head=NULL;
	}		
return 0;

}
