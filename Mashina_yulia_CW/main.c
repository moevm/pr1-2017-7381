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
} MusicalComposition;

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

MusicalComposition* swap_and_delete(MusicalComposition** phead)   
{
MusicalComposition* temp = *phead;
MusicalComposition* last = *phead;
MusicalComposition* second = *phead;
MusicalComposition* penult = *phead;
while (last->next != NULL)
{
    last = last->next;
}
penult = last->prev;
second = temp->next;
last->next = second->next;
second->next->prev = last;
temp->prev = penult->prev;
penult->prev->next = temp;
free(second);
free(penult);
temp->next = NULL;
last->prev = NULL;
*phead = last;
return *phead;
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
    int length, choice, exit = 1;
    char name[80];
    char author[80];
    char* name_for_push;
    char* author_for_push;
    int year_for_push;
    char name_for_remove[80];
    MusicalComposition* head = NULL;

    printf("Сколько элементов будет в списке?\n");
    scanf("%d", &length);
    
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

    if (length == 0) printf("Ваш список пуст\n");
    else
    {
    for (int i=0;i<length;i++)
    {
        getchar();
        printf("Название композиции:\n");
        fgets(name, 80, stdin);
        
        printf("Автор композиции:\n");
        fgets(author, 80, stdin);
        
        printf("Год создания композиции:\n");
        scanf("%d", &years[i]);

        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

        strcpy(names[i], name);
        strcpy(authors[i], author);

    }
    
    head = createMusicalCompositionList(names, authors, years, length);
    }
	do {
    printf("Вы хотите:\n");
    printf("1 - знать количество композиций\n");
    printf("2 - вывести все композиции\n");
    printf("3 - добавить композицию\n");
    printf("4 - удалить определенную композицию\n");
    printf("5 - поменять местами первый и последний элементы списка, удалив второй и предпоследний\n");
    printf("0 - выйти\n");

    scanf("%d", &choice);

    switch(choice){

      case 1: 

          printf("Количество композиций: %d\n", count(head));
          break;

      case 2:

          if (length == 0)
            printf("Печатать нечего, ваш список пуст\n");
          else 
            print_names(head);
          break;

      case 3:
          getchar();
          printf("Вы можете ввести не более 80 символов\n");
          printf("Название:\n");
          char* name_for_push = (char*)malloc(sizeof(char)*80);
          char* author_for_push = (char*)malloc(sizeof(char)*80);
          fgets(name_for_push, 80, stdin);

          printf("Автор:\n");
          fgets(author_for_push, 80, stdin);
              
          printf("Год:\n");
          scanf("%d", &year_for_push);

          (*strstr(name_for_push, "\n")) = 0;
          (*strstr(author_for_push, "\n")) = 0;

          MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
          push(&head, element_for_push);
          break;
      
      case 4:
          getchar();
          printf("Название удаляемой композиции:\n");
          fgets(name_for_remove, 80, stdin);
          (*strstr(name_for_remove, "\n")) = 0;
          removeEl(&head, name_for_remove);
          break;

      case 5:

          swap_and_delete(&head);
          break;

      case 0:

          printf("Выход\n");
          exit = 0;
          break;

      default:
          printf("Нет такой команды\n");
     }
  }
    while(exit);

	for (; head != NULL; head = head->next)
    {
        free(head->prev);
        if (head->next == NULL)
        free(head);
    }

    for (int i=0;i<length;i++){
        free(names[i]);
        free(authors[i]);
    }
    
    free(names);
    free(authors);
    free(years);

    return 0;
}