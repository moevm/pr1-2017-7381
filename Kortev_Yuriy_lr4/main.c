#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>


// Описание структуры MusicalComposition
typedef struct MusicalComposition
{
    char* name;
    char* author;
    int year;
    struct MusicalComposition* next;
    struct MusicalComposition* back;
}MusicalComposition;

// Создание структуры MusicalComposition
void removeEl(MusicalComposition* head, char* name_for_remove);
int count(MusicalComposition* head);
void print_names(MusicalComposition* head);
MusicalComposition* createMusicalComposition(char* name, char* author,int year);
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);
void push(MusicalComposition* head, MusicalComposition* element);
MusicalComposition* createMusicalComposition(char* name, char* author,int year)
{
    MusicalComposition* make=(MusicalComposition*)malloc(sizeof(MusicalComposition));
	make->name = name;
	make->author = author;
	make->year = year;
	make->next = NULL;
	make->back = NULL;
	return make;
    
}
    

// Функции для работы со списком MusicalComposition
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    MusicalComposition* head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition* tmp;
    MusicalComposition* prev=head;
    int i;
    for(i = 1; i < n; i++)
    {
        tmp = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        tmp->back = prev;
        prev->next = tmp;
        prev = tmp;
    }
    return head;
}


void push(MusicalComposition* head, MusicalComposition* element)
{
	if(head==NULL)
	{
		head=element;
	}

   MusicalComposition* tmp=head;

    while(tmp->next)
    {
        tmp=tmp->next;
    }
    element->next=NULL;
    element->back=tmp;
    tmp->next=element;
}


void removeEl(MusicalComposition* head, char* name_for_remove)
{
    MusicalComposition* tmp = head;
    
    while (strcmp(tmp->name,name_for_remove)!=0)

    {
	if(!tmp->next)
		return;
	tmp=tmp->next;
    }
        if(tmp->next!=NULL && tmp->back!=NULL)
        {
            tmp->next->back=tmp->back;
            tmp->back->next=tmp->next;
            tmp->next=NULL;
            tmp->back=NULL;
            free(tmp);
            return;
        }
        if(tmp->back==NULL)
	{
		head=head->next;
		head->back->next=NULL;
		head->back=NULL;
		free(tmp);
		return;
	}
	if(tmp->next==NULL)
	{
		tmp->back->next=NULL;
		tmp->back=NULL;
		free(tmp);
		return;
	}
	if(tmp->next==NULL && tmp->back==NULL)
	{
		free(tmp);
		return;
	}
}

    


int count(MusicalComposition* head)
{
    int n=0;
    MusicalComposition* tmp=head;
    while(tmp)
    {
        n++;
        tmp=tmp->next;
    }
    return n;
}


void print_names(MusicalComposition* head)
{
    MusicalComposition* tmp=head;
    while(tmp)
    {
        printf("%s\n", tmp->name);
        tmp=tmp->next;
    }
    
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
