
#include "MusicalComposition.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

MusicalComposition* createMusicalComposition(char* name, char* author, int year) {
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

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n) {
    MusicalComposition* mc = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition* iter = mc;
    for (int i = 1; i < n; ++i) {
        iter->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        iter->next->prev = iter;
        iter = iter->next;
    }
    return mc;
}

void push(MusicalComposition* head, MusicalComposition* element) {
    if (head == NULL) {
        head = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        head = element;
        return;
    }
    MusicalComposition* iter;
    for (iter = head; iter->next != NULL; iter = iter->next);
    element->prev = iter;
    iter->next = element;
}

void removeEl(MusicalComposition* head, char* name_for_remove) {
    MusicalComposition* iter;
    for (iter = head; iter != NULL; iter = iter->next)
        if (strcmp(iter->name, name_for_remove) == 0) {
            iter->prev->next = iter->next;
            iter->next->prev = iter->prev;
            free(iter);
            return;
        }
}

int count(MusicalComposition* head) {
    int size = 0;
    MusicalComposition* iter = head;
    for (iter = head; iter != NULL; iter = iter->next)
        ++size;
    return size;
}

void print_names(MusicalComposition* head) {
    if (head == NULL)
        return;
    MusicalComposition* iter = head;
    for (iter = head; iter != NULL; iter = iter->next)
        printf("%s\n", iter->name);
}