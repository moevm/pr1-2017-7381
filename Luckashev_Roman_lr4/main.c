#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>


// Описание структуры MusicalComposition
typedef struct MusicalComposition{
 char* name;
 char* author;
 int year;
 struct MusicalComposition* prev;
 struct MusicalComposition* next;
} MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author, int year){
	MusicalComposition* my_composition = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	my_composition->name = name;
	my_composition->author = author;
	my_composition->year = year;
	my_composition->next = NULL;
	my_composition->prev = NULL;
	return my_composition;
}

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

void push(MusicalComposition* head, MusicalComposition* element);

void removeEl(MusicalComposition* head, char* name_for_remove);

int count(MusicalComposition* head);

void print_names(MusicalComposition* head);


int main(){
    int length;
    scanf("%d\n", &length);

    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

    for (int i=0;i<length;i++)
    {
        char name[80];
        char author[80];

        fgets(name, 80, stdin);
        fgets(author, 80, stdin);
        fscanf(stdin, "%d\n", &years[i]);

        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

        strcpy(names[i], name);
        strcpy(authors[i], author);

    }
    MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
    char name_for_push[80];
    char author_for_push[80];
    int year_for_push;

    char name_for_remove[80];

    fgets(name_for_push, 80, stdin);
    fgets(author_for_push, 80, stdin);
    fscanf(stdin, "%d\n", &year_for_push);
    (*strstr(name_for_push,"\n"))=0;
    (*strstr(author_for_push,"\n"))=0;

    MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

    fgets(name_for_remove, 80, stdin);
    (*strstr(name_for_remove,"\n"))=0;

    if(head) printf("%s %s %d\n", head->name, head->author, head->year);
    int k = count(head);

    printf("%d\n", k);
    push(head, element_for_push);

    k = count(head);
    printf("%d\n", k);

    removeEl(head, name_for_remove);
    print_names(head);

    k = count(head);
    printf("%d\n", k);
    for (int i=0;i<length;i++){
        free(names[i]);
        free(authors[i]);
    }
    free(names);
    free(authors);
    free(years);

    return 0;

}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
	if(n==0) return NULL;
        MusicalComposition* List = createMusicalComposition(*array_names, *array_authors, *array_years);
        MusicalComposition* Prev = List;
	for(int i = 1; i < n; i++){
        MusicalComposition* Next = createMusicalComposition(*(array_names+i), *(array_authors+i), *(array_years+i));
	 push(Prev, Next);
	 Prev = Next;
	}
return List;
}

void push(MusicalComposition* head, MusicalComposition* element){
	if(!head) return;
	while(head->next){
	 head = head->next;
	}
	element->prev = head;
	element->next = NULL;
	head->next = element;
}

void removeEl(MusicalComposition* head, char* name_for_remove){
  while(head){
  if(!strcmp(head->name,name_for_remove)){
  if(!(head->prev) && !(head->next)){ free(head); return;}
  else
  if(!head->prev){
	*head = *(head->next);
	free(head->next->prev);
	head->next->prev = head;
	return;
	}
  else
  if(!head->next){ head->prev->next = NULL; free(head); return;}
  else{
   head->prev->next = head->next;
   head->next->prev = head->prev;
   free(head);
   return;
  }
  }
  head = head->next;
 }
}

int count(MusicalComposition* head){
	int i = 0;
	while(head){
	 i++;
	 head = head->next;
	}
	return i;
}

void print_names(MusicalComposition* head){
while(head){
  printf("%s\n", head->name);
  head = head->next;
 }
}
