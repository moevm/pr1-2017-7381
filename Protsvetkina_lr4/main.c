#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct MusicalComposition {
     char name[80];
     char author[80];
     int year;
     struct MusicalComposition* next;
     struct MusicalComposition* prev;
} MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author,int year);

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

    printf("%s %s %d\n", head->name, head->author, head->year);
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
     
    for (; head != NULL; head = head->next){
         free(head->prev);
         if (head->next == NULL)
          free(head);
      } 
    return 0;
}

MusicalComposition* createMusicalComposition(char* name, char* author,int year){
    MusicalComposition* Musical_Composition = (MusicalComposition*) malloc(sizeof(MusicalComposition));
    strncpy(Musical_Composition->name, name, 80);
    strncpy(Musical_Composition->author, author, 80);
    Musical_Composition->year = year;
    Musical_Composition->next = NULL;
    Musical_Composition->prev = NULL;
    return Musical_Composition;
}
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
    int i;
    MusicalComposition* current, *prev = NULL;
    MusicalComposition* head = NULL;

  for(i = 0; i < n; i++){
    MusicalComposition* current = (MusicalComposition*) malloc(sizeof(MusicalComposition)); 
    if (head == NULL)
        head = current;
    else
        prev->next = current;

    current->next = NULL;
    strncpy(current->name, array_names[i], 80);
    strncpy(current->author, array_authors[i], 80);
    current->year = array_years[i];
    current->prev = prev;
    prev = current;
  }  
  return head;  
}
void push(MusicalComposition* head, MusicalComposition* element){
  if (head == NULL)
    head = element;
  else {
    for(;head->next != NULL; head = head->next); 
    head->next = element;
    }
}
void removeEl(MusicalComposition* head, char* name_for_remove){

  for(;head != NULL; head = head->next)
    if (strcmp(head->name,name_for_remove) == 0){ 
    head->prev->next = head->next;
    head->next->prev = head->prev;
    free(head);
    return;
    }
}
int count(MusicalComposition* head){
    int i; 

     if(head == NULL)
      return 0;

    for(i = 1; head->next != NULL; head = head->next)
         i++;
    return i;
}
void print_names(MusicalComposition* head){
     for(; head != NULL; head = head->next)
         puts(head->name);
     }
