#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

// Описание структуры MusicalComposition
typedef struct MusicalComposition
{
    char *name;
    char *author;
    int year;
    struct MusicalComposition *next;
    struct MusicalComposition *prev;
} MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author,int year)
{
    MusicalComposition* create = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    create->name = (char*)malloc(sizeof(char)*81);
    create->author = (char*)malloc(sizeof(char)*81);
    strcpy(create->name,name);
    strcpy(create->author,author);
    create->year=year;
    create->next=NULL;
    create->prev=NULL;
    return create;
}


// Функции для работы со списком MusicalComposition
MusicalComposition* push(MusicalComposition* head, MusicalComposition* element)
{
        if (!head)
        {
            head=element;
            return head;
        }
        if ( head->next == NULL )
        {
                element->next = NULL;
                element->prev = head;
                head->next = element;
                return head;
        }

        MusicalComposition *temp = head->next;

        while (temp->next)
        {
                temp = temp->next;
        }

        element->next = NULL;
        element->prev = temp;
        temp->next = element;
        return head;
}
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    if (n==0)
        return NULL;
    MusicalComposition *head = createMusicalComposition(array_names[0],array_authors[0],array_years[0]);
    MusicalComposition *temp;
    for (int i=1;i<n;i++ )
    {
        temp=createMusicalComposition(array_names[i],array_authors[i],array_years[i]);
        push(head,temp);
    }
    return head;
}



MusicalComposition* removeEl(MusicalComposition* list, char* name_for_remove)
{
    MusicalComposition *head = list;
    if (head==NULL)
        return head;
    MusicalComposition *temp = head;

    if (strcmp(name_for_remove, temp->name) == 0)
    {
        if (temp->next)
            temp->next->prev=NULL;
        free(temp->name);
        free(temp->author);
        list=list->next;
        free(temp);
        return list;
    }
    while(temp && (strcmp(temp->name,name_for_remove) != 0))
    {
        temp=temp->next;
    }
    if (!temp)
        return list;
    if (temp->next)
    {
        temp->next->prev = temp->prev;

    }
    temp->prev->next = temp->next;
    free(temp->author);
    free(temp->name);
    free(temp);

    return list;
}

int count(MusicalComposition* head)
{
    if (head == NULL)
        return 0;
    int i=0;
    MusicalComposition* temp = head;
    while(temp)
    {
        temp = temp->next;
        i++;

    }
    return i;
}

void print_names(MusicalComposition* head)
{
    MusicalComposition* current = head;
    while(current)
    {
        printf("%s\n",current->name);
        current = current->next;
    }
    return;
}
void clear_list(MusicalComposition *head)
{
    if (!head)
    {
        return;
    }
    while(head->next)
    {
        head=head->next;
        free(head->prev->author);
        free(head->prev->name);
        free(head->prev);

    }
    free(head->author);
    free(head->name);
    free(head);
    return;
}
