#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#define N 81

typedef struct MusicalComposition
{
        char* name;
        char* author;
        int year;
        struct MusicalComposition* next;
        struct MusicalComposition* prev;
} MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author,int year)
{
        MusicalComposition* element_for_push = (MusicalComposition*)malloc(sizeof(MusicalComposition));

        element_for_push->name = (char*)malloc(sizeof(char)*N);
        element_for_push->author = (char*)malloc(sizeof(char)*N);

        strcpy(element_for_push->name, name);
        strcpy(element_for_push->author, author);
        element_for_push->year = year;
        element_for_push->next = NULL;
        element_for_push->prev = NULL;

        return element_for_push;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
        MusicalComposition* tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        if(head->next == NULL)
        {
                element->next = NULL;
                element->prev = head;
                head->next = element;
                return;
        }
        tmp = head->next;

        while (tmp->next)
        {
                tmp = tmp->next;
        }
        element->next = NULL;
        element->prev = tmp;
        tmp->next = element;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int length)
{
        if(length == 0)
            return NULL;

        MusicalComposition* head  = (MusicalComposition*)malloc(sizeof(MusicalComposition));

        head->name = (char*)malloc(sizeof(char)*N);
        head->author = (char*)malloc(sizeof(char)*N);

        strcpy(head->name , array_names[0]);
        strcpy(head->author , array_authors[0]);
        head->year = array_years[0];

        MusicalComposition* tmp;

        for(int i=1; i<length; i++)
        {
                tmp = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
                push(head , tmp);
        }
        return head;
}


void removeEl(MusicalComposition* head, char* name_for_remove)
{
        MusicalComposition *tmp;
        tmp = head;

        while (tmp->next)
        {
                if(strstr(tmp->name, name_for_remove) != NULL)
                {
			if(tmp->prev == NULL)
			{
				MusicalComposition *new_tmp = tmp->next;
				strcpy(tmp->name, new_tmp->name);
				strcpy(tmp->author, new_tmp->author);
				tmp->year = new_tmp->year;
				new_tmp->next->prev = tmp;
				tmp->next = new_tmp->next;
				free(new_tmp);
			}
			else
			{
                        	tmp->next->prev = tmp->prev;
                        	tmp->prev->next = tmp->next;
                        	free(tmp);
			}
                }
               	tmp = tmp->next;
        }
	if((strstr(tmp->name, name_for_remove) != NULL) && (tmp->next == NULL))
	{
		tmp->prev->next = NULL;
		free(tmp);
	}
}

void print_names(MusicalComposition* head)
{
	MusicalComposition* tmp;
        tmp = head->next;
            printf("%s\n", head->name);
            printf("%s\n", tmp->name);
        while (tmp->next)
        {
                if ( tmp->next->year != -1 ) printf("%s\n", tmp->next->name);
                tmp = tmp->next;
        }
}

int main(){
	int length;
	printf("Size of your list:\n");
	scanf("%d\n", &length);

	char** names = (char**)malloc(sizeof(char*)*length);
	char** authors = (char**)malloc(sizeof(char*)*length);
	int* years = (int*)malloc(sizeof(int)*length);

	for (int i=0;i<length;i++)
	{
        	char name[80];
        	char author[80];

        	fgets(name, 80, stdin);
        	fgets(author, 80, stdin);
        	fscanf(stdin, "%d\n", &years[i]);

        	(*strstr(name,"\n"))=0;
        	(*strstr(author,"\n"))=0;

        	names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        	authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

        	strcpy(names[i], name);
        	strcpy(authors[i], author);
	}
	MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);

	char name_for_remove[80];

 	fgets(name_for_remove, 80, stdin);
    	(*strstr(name_for_remove,"\n"))=0;

    	removeEl(head, name_for_remove);
	printf("Total list of authors:\n");
   	print_names(head);

    	for (int i=0;i<length;i++)
	{
        	free(names[i]);
        	free(authors[i]);
    	}

    	free(names);
    	free(authors);
    	free(years);

	return 0;
}
