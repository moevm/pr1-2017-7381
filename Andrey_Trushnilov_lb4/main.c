
#include <stdio.h>
#include <stdlib.h>

// Описание структуры MusicalComposition
typedef struct MusicalComposition{
    char name[80];
    char author[80];
    int year;
    struct MusicalComposition* next;
    struct MusicalComposition* prev;
}MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* autor,int year){
    MusicalComposition* mus=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    int i;
    for(i=0;i<80;i++){
        mus->name[i]=name[i];
        mus->author[i]=autor[i];
    }
    mus->year=year;
    mus->next=NULL;
    mus->prev=NULL;
    return mus;
}

// Функции для работы со списком MusicalComposition

void push(MusicalComposition* head, MusicalComposition* element){
    if(head->next==NULL){
        head->next=element;
        element->prev=head;
        return;
    }
    push(head->next,element);
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
    MusicalComposition* head=createMusicalComposition(array_names[0],array_authors[0],array_years[0]);
    int i;
    for(i=1;i<n;i++){
        MusicalComposition* mus=createMusicalComposition(array_names[i],array_authors[i],array_years[i]);
        push(head,mus);
    }
    return head;
}

void removeEl(MusicalComposition* head, char* name_for_remove){
    int i;
    int equal=1;
    if(head==NULL){
        return;
    }
    
    for(i=0;i<80;i++){
        if(head->name[i]=='\0')
            break;
        if(head->name[i]!=name_for_remove[i]){
            equal=0;
        }
    }
    if(equal==1){
        head->prev->next=head->next;
        head->next->prev=head->prev;
        free(head);
        return;
    }
    if(head->next==NULL)
        return;
    removeEl(head->next,name_for_remove);
}

int count(MusicalComposition* head){
    int i=0;
    MusicalComposition*cur=head;
    while(cur!=NULL){
        i++;
        cur=cur->next;
    }
    return i;
}

void print_names(MusicalComposition* head){
    if(head==NULL){
        return;
    }
    printf("%s\n",head->name);
    print_names(head->next);
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
  //  (*strstr(name_for_remove,"\n"))=0;

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






