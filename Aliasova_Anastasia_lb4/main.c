#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Описание структуры MusicalComposition
// Создание структуры MusicalComposition
typedef struct MusicalComposition{char* name; char* author; int year;
                                 struct MusicalComposition* next; 
                                 struct MusicalComposition* prev;} MusicalComposition; //?

MusicalComposition* createMusicalComposition(char* name, char* author,int year)
{
        MusicalComposition* element = (MusicalComposition*)malloc(sizeof(MusicalComposition));

        element->name=(char*)malloc(sizeof(char)*81);
        element->author=(char*)malloc(sizeof(char)*81);

        strcpy(element->name , name );
        strcpy(element->author, author);
        element->year = year;
        element->next = NULL;
        element->prev = NULL;

        return element;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
        MusicalComposition* two_element = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        if ( head->next == NULL )
        {
                element->next = NULL;
                element->prev = head;
                head->next = element;
                return;
        }

        two_element = head->next;

        while (two_element->next)
        {
                two_element = two_element->next;
        }

        element->next = NULL;
        element->prev = two_element;
        two_element->next = element;

}


MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
        if ( n == 0 )
            return NULL;

        MusicalComposition* head  = (MusicalComposition*)malloc(sizeof(MusicalComposition));

        head->name = (char*)malloc(sizeof(char)*81);
        head->author = (char*)malloc(sizeof(char)*81);

        strcpy(head->name , array_names[0]);
        strcpy(head->author , array_authors[0]);
        head->year = array_years[0];

        MusicalComposition* two_element;//не выделяю память malloc

        for ( int i = 1; i < n ; i++ )
        {
              two_element  = createMusicalComposition( array_names[i] , array_authors[i] , array_years[i] );
                push(head , two_element);
        }
	
        return head;
}


void removeEl(MusicalComposition* head, char* name_for_remove)
{
    for(; strcmp(head->name, name_for_remove); head = head->next);
    head->prev->next = head->next;
    head->next->prev = head->prev;
}


int count(MusicalComposition* head){
    int i=1;
    MusicalComposition* two_element = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        two_element = head->next;
        while (two_element != NULL)
        {
                two_element = two_element->next;
                i++;

        }
        return i;
    }

void print_names(MusicalComposition* head){
    do{
       puts(head->name);
       head = head->next;
}
    while(head != NULL);
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

        (*strstr(name,"\n"))=0;   //Функция strstr() возвращает указатель на первое вхождение в строку, на которую указывает name, строки, указанной str2 (исключая завершающий нулевой символ). Если совпадений не обнаружено, возвращается NULL.
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
