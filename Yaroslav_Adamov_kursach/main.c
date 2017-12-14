#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "api.h"

int main(){
    
    // создание списка
    
    int length;
    printf("Создание списка композиций.\nВведите количество композиций: ");
    scanf("%d\n", &length);  

    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

    for (int i=0;i<length;i++)
    {
        char name[80];
        char author[80];
        
        printf("Введите название %d-й композиции (до 80 символов): ", i+1);
        fgets(name, 80, stdin);
        printf("Введите автора этой композиции (до 80 символов): ");
        fgets(author, 80, stdin);
        printf("Введите год создания этой композиции: ");
        fscanf(stdin, "%d\n", &years[i]);

        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

        strcpy(names[i], name);
        strcpy(authors[i], author);
    }
    MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
    
    
    // работа со списком
    int rabota = 1;
    int fun = 0;
    char name_for_push[80];
    char author_for_push[80];
    int year_for_push;
    char name_for_remove[80];
    
    printf("Выберите действие, которое хотите совершить:\n");
    printf("1 - вывести на экран количество композиций.\n");
    printf("2 - вывести на экран названия композиций.\n");
    printf("3 - добавить композицию.\n");
    printf("4 - удалить композицию.\n");
    printf("5 - отсортировать список по году (по убыванию).\n");
    printf("6 - завершить работу программы.\n");
    while (rabota){
        scanf("%d\n", &fun);
        switch(fun){
            case 1:
                printf("Количество композиций: %d\n", count(head));
                break;
            case 2:
                printf("Названия композиций:\n");
                print_names(head);
                break;
            case 3:
                printf("Чтобы добавить композицию, введите её название (до 80 символов): ");
                fgets(name_for_push, 80, stdin);
                (*strstr(name_for_push,"\n"))=0;
                
                printf("Введите имя автора композиции (до 80 символов): ");
                fgets(author_for_push, 80, stdin);
                (*strstr(author_for_push,"\n"))=0;
                
                printf("Введите год создания композиции: ");
                fscanf(stdin, "%d\n", &year_for_push);
                MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
                push(head, element_for_push);
                break;
            case 4:
                printf("Чтобы удалить композицию, введите её название: ");
                fgets(name_for_remove, 80, stdin);
                (*strstr(name_for_remove,"\n"))=0;
                removeEl(head, name_for_remove);
                break;
            case 5:
                sort(head);
                printf("Список отсортирован.\n");
                break;
            case 6:
                rabota = 0;
                printf("Работа завершена.");
                break;
            default: printf("Для данной клавиши не придусмотренно никаких действий.\n");
        }
        if (rabota)
            printf("Выберите ещё одно действие или завершите работу программы.\n");
    }
        
        
    // освобождение памяти

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
