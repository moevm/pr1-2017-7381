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
   

    MusicalComposition* head=NULL, *tmp, *pred=NULL;

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


void substring(MusicalComposition** head_p, char* string)
{
    MusicalComposition* head = *head_p;
    
for (;head!=NULL;head=head->next)
    if (strstr(head->author,string)!=NULL)
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


