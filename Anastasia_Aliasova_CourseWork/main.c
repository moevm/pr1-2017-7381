#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "options.h"
#include <stddef.h>

int main(){

int length;
printf("Введите количество композиций:");
scanf("%d", &length);
char w = getchar();

char** names = (char**)malloc(sizeof(char*)*length);
char** authors = (char**)malloc(sizeof(char*)*length);
int* years = (int*)malloc(sizeof(int)*length);

MusicalComposition* head = NULL;
MusicalComposition* element;

	if (length == 0){
	head = NULL;
	printf("Пустой список\n");
	}
	else{
	for (int i=0;i<length;i++){
	char name[80];
	char author[80];

	printf("Введите название композиции:");
	fgets(name, 80, stdin);

	printf("Введите исполнителя композиции:");
	fgets(author, 80, stdin);

	printf("Введите год выхода композиции:");
	fscanf(stdin, "%d", &years[i]);
	char u =  getchar();

	(*strstr(name,"\n"))=0;   //Функция strstr() возвращает указатель на первое вхождение в строку, на которую у$
	(*strstr(author,"\n"))=0;

	names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
	authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

	strcpy(names[i], name);
	strcpy(authors[i], author);
	}
head = createMusicalCompositionList(names, authors, years, length);
}
	char name_for_push[80];
	char author_for_push[80];
	int year_for_push;
	char name_for_remove[80];

	printf("Опции для работы со списком:\n");
	printf("1 - Добавить композицию в конец списка\n");
	printf("2 - Удаление элемента списка c заданной композицией\n");
	printf("3 - Найти количество элементов списка\n");
	printf("4 - Вывести названия композиции\n");
	printf("5 - Удалить каждый третий элемент списка\n");
	printf("6 - Закончить работу со списком\n");

	int option = 0;
	int ru = 1;
	while(ru){
	printf("Напишите номер команды:\n");
	scanf("%d", &option);
	char w = getchar();

	switch (option){
		case 1:
			printf("Введите имя композиции:\n");
		 	fgets(name_for_push, 80, stdin);
			(*strstr(name_for_push,"\n"))=0;

			printf("Введите автора композиции:\n");
			fgets(author_for_push, 80, stdin);
			(*strstr(author_for_push,"\n"))=0;

			printf("Введите год выхода композиции:\n");
			fscanf(stdin, "%d", &year_for_push);

			MusicalComposition* element = createMusicalComposition(name_for_push, author_for_push, year_for_push);
			
			if(head == NULL)
			head = element;
			else
			push(head,element);
			
			printf("Названия композиций вместе с добавленным элементом:\n");
			print_names(head);
			break;

		case 2:
			if(head == NULL)
       		  	printf("Пустой список\n");
		 	else{
			printf("Напишите композицию, которую вы хотите удалить\n");
			fgets(name_for_remove, 81, stdin);
   			(*strstr(name_for_remove,"\n"))=0;
			removeEl(head, name_for_remove);
			printf("Список композиции без удаленного элемента:\n");
			print_names(head);	
			}
			break;
		case 3:
			if(head == NULL)
                        printf("Пустой список\n");
			else
			printf("Количество композиции равно:%d\n",count(head));
			break;

		case 4:
			if(head == NULL)
                        printf("Пустой список\n");
                	else{
                        printf("Названия композиции:\n");
			print_names(head);
			}
			break;
		case 5:
			if(head == NULL)
                        printf("Пустой список\n");
			else{
			printf("Удаление каждого третьего элемента\n");
			RemoveEvery(&head, 3);
			print_names(head);
			}
			break;
		case 6:
			printf("До скорой встречи!\n");
			ru = 0;
			break;
		default:
			printf("Данные некорректны! Попробуйте снова.\n");
}
}
	for (int i=0;i<length;i++){
	free(names[i]);
	free(authors[i]);
	}
	free(names);
	free(authors);
	free(years);

	MusicalComposition*tnp = head->next;

	while(tnp != NULL){
	free(tnp->prev->name);
	free(tnp->prev->author);
	free(tnp->prev);
	tnp = tnp->next;
	}
	if(tnp = NULL){
	free(head->name);
        free(head->author);
        free(head);
	}

	free(tnp);
	return 0;
}
