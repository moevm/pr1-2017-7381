#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "opt.h"

int main() {
	int len;
	printf("Введите количество композиций:\n");
	scanf("%d", &len);
	char m = getchar();

	char** names = (char**)malloc(len*sizeof(char*));
	char** authors = (char**)malloc(len*sizeof(char*));
	int* years = (int*)malloc(len*sizeof(int));

	MusicalComposition* head = NULL;
	MusicalComposition* element_for_push;

	if (len == 0) {
		head == NULL;
		printf("Список пуст!\n");
		exit(0);
	}
	else {
		for (int i = 0; i < len; i++) {
			char name[80];
			char author[80];
			printf("Введите название композиции:\n");
			fgets(name, 80, stdin);
			printf("Введите автора композиции:\n");
			fgets(author, 80, stdin);
			printf("Введите год создания:\n");
			fscanf(stdin, "%d", &years[i]);
			char n = getchar();

			(*strstr(name,"\n"))=0;
			(*strstr(author,"\n"))=0;

			names[i] = (char*)malloc((strlen(name)+1)*sizeof(char*));
			authors[i] = (char*)malloc((strlen(author)+1)*sizeof(char*));

			strcpy(names[i], name);
			strcpy(authors[i], author);

		}
	}

	head = createMusicalCompositionList(names, authors, years, len);

	char name_for_push[81];
	char author_for_push[81];
	int year_for_push;

	char name_for_remove[81];

	printf("Действия со списком:\n");
	printf("1 - Добавление новой композиции в конец списка.\n");
	printf("2 - Удаление композиции из списка.\n");
	printf("3 - Удаление композиций, стоящих на нечетных позициях.\n");
	printf("4 - Вывод количества композиций в списке.\n");
	printf("5 - Вывод названий композиций в списке.\n");
	printf("6 - завершение работы со списком.\n");

	int opt;
	int flag = 1;

	while (flag) {
		printf("Введите номер возможного действия со списком:\n");
		scanf("%d", &opt);
		char t = getchar();
		switch (opt) {

		case 1:
			printf("Введите название композиции:\n");
			fgets(name_for_push, 81, stdin);
			(*strstr(name_for_push,"\n"))=0;
			printf("Введите автора композиции:\n");
			fgets(author_for_push, 81, stdin);
			(*strstr(author_for_push,"\n"))=0;
			printf("Введите год создания:\n");
			fscanf(stdin, "%d", &year_for_push);
			char k = getchar();
			MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
			if (head == NULL) {
				head = element_for_push;
			}
			else {
				push(head, element_for_push);
			}
			break;
		case 2:
			if (head == NULL) {
				printf("Список пуст!\n");
			}
			else {
				printf("Введите название композиции, которую вы хотите удалить:\n");
				fgets(name_for_remove, 81, stdin);
				(*strstr(name_for_remove,"\n"))=0;
				removeEl(&head, name_for_remove);
			}
			break;
		case 3:
			if (head == NULL) {
				printf("Список пуст!\n");
			}
			else {
				printf("Композиции, стоящие на нечетных местах были удалены.\n");
				remove_odd(head);
				printf("оставшиеся композиции в списке:\n");
				print_names(head);
			}
			break;
		case 4:
			if (head == NULL) {
				printf("Список пуст!\n");
			}
			else {
				printf("Количество композиций: %d\n", print_number(head));
			}
			break;
		case 5:
			if (head == NULL) {
				printf("Список пуст!\n");
			}
			else {
				printf("Названия композиций в списке:\n");
				print_names(head);
			}
			break;
		case 6:
			printf("До свидания!\n");
			flag = 0;
			break;
		default:
			printf("Необходимо ввести число от 1 до 6!\n");
		}

	}

	if (head != NULL) {
		for (int i = 0; i < len; i++) {
			free(names[i]);
			free(authors[i]);
		}

		free(names);
		free(authors);
		free(years);

		MusicalComposition* tmp = head->next;

		while (tmp != NULL) {
			free(tmp->prev->name);
			free(tmp->prev->author);
			free(tmp->prev);
			tmp = tmp->next;
		}

		if (tmp = NULL) {
			free(head->name);
			free(head->author);
			free(head);
		}

		free(tmp);
	}
return 0;
}
