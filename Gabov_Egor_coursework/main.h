#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        element_for_push->name = (char*)malloc(sizeof(char)*81);
        element_for_push->author = (char*)malloc(sizeof(char)*81);

        strcpy(element_for_push->name , name );
        strcpy(element_for_push->author,author);
        element_for_push->year = year;
        element_for_push->next = NULL;
        element_for_push->prev = NULL;

        return element_for_push;
}
// добавление в нулевой
void push(MusicalComposition* head, MusicalComposition* element)
{
        if ( !head )               //
	{
		head = element;
		return; 
	}

	if ( head->next == NULL )
        {
                element->next = NULL;
                element->prev = head;
                head->next = element;
                return;
        }
	
        MusicalComposition* tmp = head->next;

        while (tmp->next)
        {
                tmp = tmp->next;
        }

        element->next = NULL;
        element->prev = tmp;
        tmp->next = element;
	
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years,int length)
{
        if ( length == 0 )
            return NULL;
	
        MusicalComposition* head  = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	
        head->name = (char*)malloc(sizeof(char)*81);
        head->author = (char*)malloc(sizeof(char)*81);
	
        strcpy(head->name , array_names[0]);
        strcpy(head->author , array_authors[0]);
        head->year = array_years[0];
	head->next = NULL;
	head->prev = NULL;
	
        MusicalComposition* tmp;
	
	for ( int i = 1; i < length ; i++ )
        {
                tmp = createMusicalComposition( array_names[i] , array_authors[i] , array_years[i] );
                push(head , tmp);
        }
        return head;
}


void removeEl(MusicalComposition* head, char* name_for_remove)
{
	MusicalComposition *tmp = head;

	if ( strcmp ( head->name , name_for_remove ) == 0 )
	{
		*head = *head->next;
	}
	
        while ( tmp->next  )
        {
                if ( strcmp( tmp->name , name_for_remove ) == 0 )
                {
                        tmp->next->prev = tmp->prev;
                        tmp->prev->next = tmp->next;
			free(tmp->author);
			free(tmp->name);
			free(tmp);
                }
                tmp = tmp->next;
        }
	
	if ( strcmp( tmp->name , name_for_remove ) == 0 )
	{
		tmp->prev->next = NULL;
		free(tmp);
	}

}

int count(MusicalComposition* head)
{
        int i=1;

	if (!head)
		return 0;

	MusicalComposition* tmp = head;
	while (tmp->next)
        {
                tmp = tmp->next;
                i++;

        }
        return i;

}

void print_names(MusicalComposition* head)
{
	if ( !head )
		return;
	
	MusicalComposition* tmp = head;
	
	while( tmp )
	{	
		printf("%s\n" , tmp->name);
		tmp = tmp->next;	
	}
}

void print_srez_spiska( MusicalComposition* head , int start , int end )
{

	MusicalComposition* tmp = head;
	MusicalComposition* temp = NULL; 

	if (head)
		temp = head -> next ; 
	
	int count=0;
	
	while (temp)
        {
                temp = temp->next;
                count++;
        }

	if ( end > count )
	{	
		end = count ;	
	}
	
	for ( int k = start ; k <= end ; k++ )
	{	
		printf("название музыкальной композиции [%d]: %s \n " , k , tmp ->name );
		printf("автор музыкальной композиции [%d]: %s \n" , k , tmp -> author );
		printf("год создания музыкальной композиции [%d]: %d\n " , k ,tmp->year );
			
		tmp = tmp->next;	
	}	
}


























