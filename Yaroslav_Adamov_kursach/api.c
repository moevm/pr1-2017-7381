#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "api.h"

// Создание структуры MusicalComposition
MusicalComposition* createMusicalComposition(char* name, char* author, int year){
    MusicalComposition* new_composition = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    new_composition->name=(char*)malloc(81*sizeof(char));
    new_composition->author=(char*)malloc(81*sizeof(char));
    strncpy(new_composition->name, name, 80);
    strncpy(new_composition->author, author, 80);
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
void removeEl(MusicalComposition **head, char* name_for_remove){
    MusicalComposition* comp;
    for (comp = *head; comp!=NULL; comp=comp->next)
        if (strcmp(comp->name,name_for_remove)==0){
            if (comp->prev == NULL){ // удаляется head
                if (comp->next == NULL){ // в списке всего 1 элемент
                    *head = NULL;
                } else{ // удаляется head, в списке больше 1 элемента
                    comp->next->prev=NULL;
                    *head = comp->next;
                }
            } else{
                if (comp->next == NULL){ // удаляется последний элемент
                    comp->prev->next = NULL;
                } else{ // остальные случаи
                    comp->next->prev = comp->prev;
                    comp->prev->next = comp->next;
                }
            }
            break;
        }
    free (comp->name);
    free (comp->author);
    free (comp);
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

// сортировка списка по убыванию года
void sort(MusicalComposition* head){
    for (MusicalComposition* comp_1 = head; comp_1!=NULL; comp_1=comp_1->next){
        for (MusicalComposition* comp_2 = head; comp_2!=NULL; comp_2=comp_2->next){
            if (comp_1->year < comp_2->year){
                MusicalComposition comp_3 = *comp_1;
                strcpy (comp_1->name, comp_2->name);
                strcpy (comp_2->name, comp_3.name);
                strcpy (comp_1->author, comp_2->author);
                strcpy (comp_2->author, comp_3.author);
                comp_1->year = comp_2->year;
                comp_2->year = comp_3.year;
            }
        }
    }
}
