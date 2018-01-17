#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct MusicalComposition 
{
     char* name;
     char* author;
     int year;
     struct MusicalComposition* next;
     struct MusicalComposition* prev;
}MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
    MusicalComposition* composition = (MusicalComposition*) malloc(sizeof(MusicalComposition));
    composition->name = name;
    composition->author = author;
    composition->year = year;
    composition->next = NULL;
    composition->prev = NULL;
    return composition;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    if(n==0) 
        return NULL;
    int i = 1;
    MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition *list = head;
    for (; i < n; i++)
    {
        list->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        list->next->prev=list; list=list->next;
    }
    return head;
}
void push(MusicalComposition** phead, MusicalComposition* element)
{
    MusicalComposition* head = *phead;  
    if(!head) {
        *phead=element; return;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = element;
    element->prev = head;
}
void removeEl(MusicalComposition** phead, char* name_for_remove)
{
    MusicalComposition* head = *phead;
    for(;head!=NULL;)
    {
        
        if(strcmp(head->name,name_for_remove))
        {
            head = head->next;
        }
 
      else {  
         if (head->prev==NULL) 
        {
            if (head->next==NULL)
            {
                *phead=head->next;
                free(head); break;
            }
            *phead=head->next;
            head=head->next;
            free(head->prev);
            head->prev=NULL;
            return;
        }
        if (head->next==NULL)
        {
            head->prev->next = head->next;
            free(head); break;
        }
        head->prev->next = head->next;
        head->next->prev = head->prev;
        MusicalComposition* list = head->next;
        free(head);
        head=list;
        }
   }
}
int count(MusicalComposition* head)
{
    int amm = 0;
    for (; head!=NULL; head=head->next)
        amm++;
    return amm;
}
void print_names(MusicalComposition* head)
{
    for (; head != NULL; head=head->next)
        printf("%s\n", head->name);
}

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

    if (head) printf("%s %s %d\n", head->name, head->author, head->year);
    int k = count(head);

    printf("%d\n", k);
    push(&head, element_for_push);

    k = count(head);
    printf("%d\n", k);

    removeEl(&head, name_for_remove); 
    print_names(head);

    k = count(head);
    printf("%d\n", k);

    for (int i=0;i<length;i++){
        free(names[i]);
        free(authors[i]);
    }
    free(names);
return 0; 
}
