#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct MusicalComposition {
     char* name;
     char* author;
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

void remove_div(MusicalComposition* head);

int main(){
  int length;

   char name_for_push[80];
   char author_for_push[80];
   int year_for_push;
   char name_for_remove[80];

    char name[80];
    char author[80];
    MusicalComposition* head = NULL;

    printf("Input the number of elements the List will consist of\n");
    scanf("%d", &length);

    char** names = (char**)malloc(sizeof(char*)*(length)); 
    char** authors = (char**)malloc(sizeof(char*)*(length));
    int* years = (int*)malloc(sizeof(int)*length);
    
    if (length == 0)
      printf("Well done! An empty list!\n");
    else {
    for (int i=0; i < length; i++){
         getchar();
         printf("Input the title of the composition\n");
         fgets(name, 80, stdin);

         printf("Input its author\n");
         fgets(author, 80, stdin);

         printf("Input the year of its release\n");
         scanf("%d", &years[i]);
 

         (*strstr(name, "\n")) = 0;
         (*strstr(author, "\n")) = 0;

         names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
         authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

         strcpy(names[i], name);
         strcpy(authors[i], author);
       }

    head = createMusicalCompositionList(names, authors, years, length);
}
    int choice, exit_flag = 0;

    do {
    printf("Choose what you're willing to do, Sir:\n");
    printf("1 to print the number of the compositions\n");
    printf("2 to print all the compositions\n");
    printf("3 to add a composition\n");
    printf("4 to remove a composition by its title \n");
    printf("5 to remove all the compositions which year of release is divisible by 4\n");
    printf("9 to quit\n");

    scanf("%d", &choice);

    switch(choice){

      case 1: 

          printf("%d\n", count(head));
          break;

      case 2:

          if (length == 0)
            printf("Nothing to print! Your List is empty :c \n");
          else 
            print_names(head);
          break;

      case 3:
          getchar();
          printf("Input the title of the composition (up to 80 characters)\n");
          fgets(name_for_push, 80, stdin);

          printf("Input its author\n");
          fgets(author_for_push, 80, stdin);
              
          printf("Input the year of its release\n");
          scanf("%d", &year_for_push);

          (*strstr(name_for_push, "\n")) = 0;
          (*strstr(author_for_push, "\n")) = 0;

          MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
          push(head, element_for_push);
          break;
      
      case 4:
          getchar();
          printf("Input the title of the composition to remove it:\n");
          fgets(name_for_remove, 80, stdin);
          (*strstr(name_for_remove, "\n")) = 0;
          removeEl(head, name_for_remove);
          break;

      case 5:

          remove_div(head);
          break;

      case 9:

          printf("Session finished successfully!\n");
          exit_flag = 1;
          break;

      default:
          printf("Wrong input! Have another try!\n");
     }
  }
    while(!exit_flag);

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
    Musical_Composition->name = name;
    Musical_Composition->author = author;
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
    current->name = array_names[i];
    current->author = array_authors[i];
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
      if (head->next == NULL && head->prev == NULL) // case of only 1 element existing
      free(head);
      else if (head->next == NULL) {// case of removing the last element
        head = head->prev;
        free(head->next);
        head->next = NULL;
      }
      else if (head->prev == NULL){ // case of removing the head
        *head = *(head->next);
        free(head->next->prev);
        head->next->prev = head;
        head->prev = NULL;
        }  
      else {                        // anything else 
      head->prev->next = head->next;
      head->next->prev = head->prev;
      free(head);
      }
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

void remove_div(MusicalComposition* head){
 
    for(;head != NULL; head = head->next)
    if (head->year % 4 == 0){ 
      if (head->next == NULL && head->prev == NULL) // case of only 1 element existing
      free(head);
      else if (head->next == NULL) {// case of removing the last element
        head = head->prev;
        free(head->next);
        head->next = NULL;
      }
      else if (head->prev == NULL){ // case of removing the head
        *head = *(head->next);
        free(head->next->prev);
        head->next->prev = head;
        head->prev = NULL;
        }  
      else {                        // anything else 
      head->prev->next = head->next;
      head->next->prev = head->prev;
      free(head);
      }
    }
}