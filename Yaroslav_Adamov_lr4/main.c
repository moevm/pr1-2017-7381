#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

// Описание структуры MusicalComposition
typedef struct MusicalComposition{
    char *name;
    char *author;
    int year;
    struct MusicalComposition* next;
    struct MusicalComposition* prev;
} MusicalComposition;


// Создание структуры MusicalComposition
MusicalComposition* createMusicalComposition(char* name, char* author, int year){
    MusicalComposition* new_composition = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    new_composition->name=(char*)malloc(81*sizeof(char));
    new_composition->author=(char*)malloc(81*sizeof(char));
    strcpy(new_composition->name, name);
    strcpy(new_composition->author, author);
    new_composition->year=year;
    new_composition->next = NULL;
    new_composition->prev = NULL;
    return new_composition;
}


// Функции для работы со списком MusicalComposition
//
// Создание списка музыкальных композиций
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
    MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition *comp = head;
    int i=0;
    for (i=1;i<n;i++){
        comp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        comp->next->prev=comp;
        comp=comp->next;
    }
    return head;
}

// Добавление новой композиции в конец списка
void push(MusicalComposition* head, MusicalComposition* element){
    MusicalComposition* comp = head;
    while (comp->next!=NULL)
        comp=comp->next;
    comp->next=element;
    element->prev=comp;
}


// Удаление элемента, у которого name равно name_for_remove
void removeEl(MusicalComposition* head, char* name_for_remove){
    for (MusicalComposition* comp = head; comp!=NULL; comp=comp->next)
        if (strcmp(comp->name,name_for_remove)==0){
            comp->next->prev = comp->prev;
            comp->prev->next = comp->next;
            break;
        }
}

// Возвращает количество композиций
int count(MusicalComposition* head){
    int count=0;
    for (MusicalComposition* comp = head; comp!=NULL; comp=comp->next)
        count++;
    return count;
}

// Выводит названия композиций
void print_names(MusicalComposition* head){
    for (MusicalComposition* comp=head; comp!=NULL; comp=comp->next)
        printf("%s\n",comp->name);
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

    fgets(name_for_push, 80, stdin);
    fgets(author_for_push, 80, stdin);
    fscanf(stdin, "%d\n", &year_for_push);
    (*strstr(name_for_push,"\n"))=0;
    (*strstr(author_for_push,"\n"))=0;

    MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

    char name_for_remove[80];
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

    head = head->next;
    while(head->next!=NULL){
        free (head->prev);
        head = head->next;
    }
    free (head);
    
    return 0;
}
