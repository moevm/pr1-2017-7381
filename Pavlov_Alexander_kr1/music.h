
#pragma once

typedef struct MusicalComposition {
    char* name;
    char* author;
    int year;
    struct MusicalComposition* prev;
    struct MusicalComposition* next;
} MusicalComposition;

MusicalComposition* createMusicalComposition(char*, char*, int);

void push(MusicalComposition**, MusicalComposition*);
void removeEl(MusicalComposition**, char*);

int count(MusicalComposition*);
void print_names(MusicalComposition*);