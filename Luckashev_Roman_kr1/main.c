#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "MusicalComposition.h"

int main(){
    MusicalComposition* List = NULL;
    int input;
    int length;
    char c;

    printf("Length of Initial List:\n> ");
    scanf("%d", &length);
    c = getchar();
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

    for (int i=0;i<length;i++)
    {
        char name0[80];
        char author0[80];

	printf("Name:\n> ");
        fgets(name0, 80, stdin);

	printf("Author:\n> ");
        fgets(author0, 80, stdin);

	printf("Year:\n> ");
        fscanf(stdin, "%d", &years[i]);

	c = getchar();

        (*strstr(name0,"\n"))=0;
        (*strstr(author0,"\n"))=0;

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name0)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author0)+1));

        strcpy(names[i], name0);
        strcpy(authors[i], author0);

    }
    List = createMusicalCompositionList(names, authors, years, length);

    for (int i=0;i<length;i++){
        free(names[i]);
        free(authors[i]);
    }

    free(names);
    free(authors);
    free(years);

    while(1){
	input = -1;
	printf("Type in command:\n0: exit\n1: push\n2: print names\n3: remove element by name\n4: insert task\n5: count number of musical compositions in list\n> ");

	scanf("%d", &input);
	while(c = getchar() != '\n') {}

	switch (input){
		case 0:{
		free_list(&List);
		return 0;
		}

		case 1:{

		char* name = (char*)malloc(80*sizeof(char));
		char* author = (char*)malloc(80*sizeof(char));
		int year;

		printf("Name:\n> ");
		fgets(name, 80, stdin);

		printf("Author:\n> ");
     	        fgets(author, 80, stdin);

		printf("Year:\n> ");
     	        fscanf(stdin, "%d", &year);

	        c = getchar();

		(*strstr(name,"\n"))=0;
	        (*strstr(author,"\n"))=0;

		MusicalComposition* insert = createMusicalComposition(name,author,year);

		push(&List, insert);

		free(name);
		free(author);
		break;
		}

		case 2:{
		printf("Names of Musical Compositions currently in list:\n");
		print_names(List);
		printf("\n");
		break;
		}

		case 3:{
		printf("Name of composition to delete:\n> ");

		char* name = (char*)malloc(80*sizeof(char));

		fgets(name, 80, stdin);
                (*strstr(name,"\n"))=0;

		removeEl(&List, name);

		free(name);
		break;
		}

		case 4:{
		printf("Function inserts two Items after each even element of the list.\n");

		char* name = (char*)malloc(80*sizeof(char));
                char* author = (char*)malloc(80*sizeof(char));
                int year;

		char* name1 = (char*)malloc(80*sizeof(char));
                char* author1 = (char*)malloc(80*sizeof(char));
                int year1;

		printf("Item #1 name:\n> ");
		fgets(name, 80, stdin);

		printf("Item #1 author:\n> ");
                fgets(author, 80, stdin);

		printf("Item #1 year:\n> ");
                fscanf(stdin, "%d", &year);

                c = getchar();

		(*strstr(name,"\n"))=0;
                (*strstr(author,"\n"))=0;

		printf("Item #2 name:\n> ");
		fgets(name1, 80, stdin);

		printf("Item #2 author:\n> ");
                fgets(author1, 80, stdin);

		printf("Item #2 year:\n> ");
                fscanf(stdin, "%d", &year1);

		c = getchar();

		(*strstr(name1,"\n"))=0;
                (*strstr(author1,"\n"))=0;

		MusicalComposition* item1 = createMusicalComposition(name, author, year);
		MusicalComposition* item2 = createMusicalComposition(name1, author1, year1);

		insert_task(List, item1, item2);

		free_list(&item1);
		free_list(&item2);

		free(name);
		free(name1);
		free(author);
		free(author1);

		break;
		}

		case 5:{
		printf("Number of items in list: %d\n", count(List));
		break;
		}
	}
    }
return 0;
}
