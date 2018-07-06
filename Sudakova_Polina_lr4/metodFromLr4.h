#include "structComposition.h"
MusicalComposition* createMusicalComposition(char *name, char* autor, int year);
MusicalComposition* createMusicalCompositionList(char **arrayNames,char** arrayAutors,int* arrayYears,int n);
void push(MusicalComposition* head,MusicalComposition* element);
void removeEi(MusicalComposition* head, char* nameForRemove);
int count(MusicalComposition* head);
void print_names(MusicalComposition* head);
