
#include "mc.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
    MusicalComposition* mc = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    mc->name = (char*)malloc(81 * sizeof(char));
    strcpy(mc->name, name);
    mc->author = (char*)malloc(81 * sizeof(char));
    strcpy(mc->author, author);
    mc->year = year;
    mc->next = NULL;
    mc->prev = NULL;
    return mc;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    if (n <= 0)
        return NULL;
    MusicalComposition *mc = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition *iter = mc;
    for (int i = 1; i < n; ++i)
    {
        iter->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        iter->next->prev = iter;
        iter = iter->next;
    }
    return mc;
}

void push(MusicalComposition** head, MusicalComposition *element)
{
    if (*head == NULL) {
        *head = element;
        return;
    }
    MusicalComposition* iter;
    for (iter = *head; iter->next; iter = iter->next);
    element->prev = iter;
    iter->next = element;
}

void removeEl(MusicalComposition** head, char* name_for_remove)
{
    if (*head == NULL)
        return;
    MusicalComposition* iter = *head;
    MusicalComposition* temp;
    while (iter != NULL) {
        temp = iter;
        iter = iter->next;
        if (strcmp(temp->name, name_for_remove) == 0)
        {
            if (temp == *head)
                *head = iter;
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp->name);
            free(temp->author);
            free(temp);
        }
    }
}

int count(MusicalComposition* list)
{
    int size = 0;
    MusicalComposition* iter = list;
    while (iter != NULL) {
        ++size;
        iter = iter->next;
    }
    return size;
}

void print_names(MusicalComposition* list) {
    MusicalComposition* iter = list;
    while (iter != NULL) {
        printf("%s\n", iter->name); 
        iter = iter->next;
    }
}