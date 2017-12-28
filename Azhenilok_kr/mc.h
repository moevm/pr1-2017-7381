
#ifndef __MC_H__
#define __MC_H__

typedef struct MusicalComposition {
    char* name;
    char* author;
    int year;
    struct MusicalComposition* prev;
    struct MusicalComposition* next;
} MusicalComposition;

MusicalComposition* createMusicalComposition(char*, char*, int);

MusicalComposition* createMusicalCompositionList(char**, char**, int*, int);

void push(MusicalComposition**, MusicalComposition*);

void removeEl(MusicalComposition**, char*);

int count(MusicalComposition*);

void print_names(MusicalComposition*);

#endif // __MC_H__