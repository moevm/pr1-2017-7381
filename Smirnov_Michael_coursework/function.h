#pragma once

typedef struct MusicalComposition
{
    char* name;
    char* author;
    int year;
    struct MusicalComposition* next;
    struct MusicalComposition* prev;
} MusicalComposition;


MusicalComposition* createMusicalComposition(char* name, char* author,int year);
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);
MusicalComposition* push(MusicalComposition* head, MusicalComposition* element);
int count(MusicalComposition* head);

void halfsort(MusicalComposition* head);
