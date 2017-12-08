#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

// Описание структуры MusicalComposition
typedef struct MusicalComposition
{
    char *name;
    char *author;
    int year;
    struct MusicalComposition *next;
    struct MusicalComposition *prev;
} MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author,int year)
{
    MusicalComposition* create = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    create->name = name;
    create->author = author;
    create->year=year;
    create->next=NULL;
    create->prev=NULL;
    return create;
}


// Функции для работы со списком MusicalComposition
void push(MusicalComposition* head, MusicalComposition* element)
{
    MusicalComposition* temp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        if ( head->next == NULL )
        {
                element->next = NULL;
                element->prev = head;
                head->next = element;
                return;
        }

        temp = head->next;

        while (temp->next)
        {
                temp = temp->next;
        }

        element->next = NULL;
        element->prev = temp;
        temp->next = element;
        return;
}
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    if (n==0)
        return NULL;
    MusicalComposition *head = createMusicalComposition(array_names[0],array_authors[0],array_years[0]);
    MusicalComposition *temp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    for (int i=1;i<n;i++ )
    {
        temp=createMusicalComposition(array_names[i],array_authors[i],array_years[i]);
        push(head,temp);
    }
    return head;
}



void removeEl(MusicalComposition* head, char* name_for_remove)
{
    if (head==NULL)
        return;
    MusicalComposition *temp = head;

    if (strcmp(name_for_remove, temp->name) == 0)
    {
        head=head->next;
        free(temp);
        return;
    }
    while(temp && (strcmp(temp->name,name_for_remove) != 0))
    {
        temp=temp->next;
    }
    if (temp->next)
    {
        temp->next->prev = temp->prev;

    }
    temp->prev->next = temp->next;
    free(temp);
    return;
}

int count(MusicalComposition* head)
{
    if (head == NULL)
        return 0;
    int i=0;
    MusicalComposition* temp = head;
    while(temp)
    {
        temp = temp->next;
        i++;

    }
    return i;
}

void print_names(MusicalComposition* head)
{
    MusicalComposition* current = head;
    while(current)
    {
        printf("%s\n",current->name);
        current = current->next;
    }
    return;
}
void clear_list(MusicalComposition *head)
{
    if (!head)
    {
        return;
    }
    while(head->next)
    {
        head=head->next;
      //  free(head->prev->author);
      //  free(head->prev->name);
        free(head->prev);

    }

    free(head);
    //free(head->name);
    //free(head->author);
    return;
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

    clear_list(head);
    return 0;

}
