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
 }MusicalComposition;// Описание структуры MusicalComposition

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author,int year)
{    MusicalComposition* Musical_Composition;
     Musical_Composition=(MusicalComposition*)malloc(sizeof(MusicalComposition));
     Musical_Composition->name=name;
     Musical_Composition->author=author;
     Musical_Composition->year=year;
     Musical_Composition->prev=NULL;
     Musical_Composition->next=NULL;
 return Musical_Composition;
}

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{  int i=0;
   

    MusicalComposition* head, *tmp, *pred=NULL;

    for(i=0; i<n;i++)
        {tmp = createMusicalComposition ( array_names[i], array_authors[i],array_years[i]);
         tmp->prev=pred;

if (i!=0)
        pred->next=tmp;
        

else

    head=tmp;

         pred=tmp;
}
    return head;
}

void push(MusicalComposition* head, MusicalComposition* element)
{if (head==NULL)
    *head=*element;
 else{
for(;head->next!=NULL;head=head->next);
    
        head->next=element;
        element->prev=head;
 }
}

void removeEl(MusicalComposition** head_p, char* name_for_remove)
{
    MusicalComposition* head = *head_p;
    
for (;head!=NULL;head=head->next)
    if (strcmp(head->name,name_for_remove)==0)
    if (head->next==NULL && head->prev==NULL)
    {*head_p=NULL;
    free(head);
    }
    else if(head->next!=NULL && head->prev==NULL)
    {head->next->prev=NULL;
     *head_p=head->next;
    free(head);
 }
    else if (head->next==NULL && head->prev!=NULL)
    {head->prev->next=NULL;
    free (head);
 }
    else 
   {head->next->prev=head->prev;
        head->prev->next=head->next;
        free (head);
     }
    
        
       
}

int count(MusicalComposition* head)
{int k=0;
for (;head!=NULL;head=head->next)
    k++;
 return k;
}

void print_names(MusicalComposition* head)
{
for (;head!=NULL;head=head->next)
    puts(head->name);
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

    printf("%s %s %d\n", head->name, head->author, head->year);
    int k = count(head);

    printf("%d\n", k);
    push(head, element_for_push);

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
    free(authors);
    free(years);

    return 0;

}