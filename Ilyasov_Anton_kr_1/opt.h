#pragma once

typedef struct MusicalComposition{
    char *name;
    char *author;
    int year;
    struct MusicalComposition* next;
    struct MusicalComposition* prev;
} MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author,int year);
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);
void push(MusicalComposition* head, MusicalComposition* element);
void removeEl(MusicalComposition** head, char* name_for_remove);
int count(MusicalComposition* head);
void deleting(MusicalComposition* head);
