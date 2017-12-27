#pragma once

typedef struct MusicalComposition{
char* name;
char* author;
int year;
struct MusicalComposition* next;
struct MusicalComposition* prev;
}MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author,int year);
void push(MusicalComposition* head, MusicalComposition* element);
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);
void removeEl(MusicalComposition* head, char* name_for_remove);
int count(MusicalComposition* head);
void print_names(MusicalComposition* head);
MusicalComposition* RemoveEvery(MusicalComposition** head, size_t number);
