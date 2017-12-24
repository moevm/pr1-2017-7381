#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "opt.h"

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author,int year){
    MusicalComposition* newMC=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    newMC->name = (char*)malloc(81*sizeof(char));
    strncpy(newMC->name, name, 81);
    newMC->author = (char*)malloc(81*sizeof(char));
    strncpy(newMC->author, author, 81);
    newMC->year = year;
    newMC->next = NULL;
    newMC->prev = NULL;                                                          
    return newMC;
}

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
    MusicalComposition* head = createMusicalComposition( array_names[0],  array_authors[0], array_years[0]);
    MusicalComposition* tmp = head;
    for(int i=1; i<n; ++i){
        MusicalComposition* newMC = createMusicalComposition( array_names[i],  array_authors[i], array_years[i]);
        tmp->next = newMC;
        newMC->prev = tmp;
        tmp = tmp->next;
    }
    return head;
}

void push(MusicalComposition* head, MusicalComposition* element){
    
    
    MusicalComposition* tmp = head;
    
    while(tmp->next != NULL)
        tmp=tmp->next;
  
    tmp->next = element;
    element->prev = tmp;
}

void removeEl(MusicalComposition** head, char* name_for_remove){
     MusicalComposition* tmp;
        for (tmp = *head; tmp!=NULL; tmp=tmp->next)
            if (strcmp(tmp->name,name_for_remove)==0){
                if (tmp->prev == NULL){ 
                    if (tmp->next == NULL){ 
                        *head = NULL;
                    } else{ 
                        tmp->next->prev=NULL;
                        *head = tmp->next;
                    }
                } else{
                    if (tmp->next == NULL){ 
                        tmp->prev->next = NULL;
                    } else{ 
                        tmp->next->prev = tmp->prev;
                        tmp->prev->next = tmp->next;
                    }
                }
                break;
            }

}

int count(MusicalComposition* head){
    MusicalComposition* tmp = head;
    int size;
    for( size = 0; tmp != NULL ; size++)
        tmp = tmp->next;
    return size;
}

void print_names(MusicalComposition* head){
    MusicalComposition* tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next)
        printf("%s\n",tmp->name);
}

void deleting(MusicalComposition* head){ 
    MusicalComposition* tmp; 
    while(1){ 
        if (head->next==NULL)  //Если дальше эл-тов нет прерываю цикл
            break; 
        else if (head->next->next==NULL){ //Если следующий эл-т последний(он чётный) 
            free(head->next->name); 
            free(head->next->author); 
            free(head->next); 
            head->next = NULL; 
    break; 
    } 
        else {  // Если больше одного элемента
            tmp = head->next;
            head=head->next->next; 
            tmp->prev->next=tmp->next; 
            tmp->next->prev=tmp->prev; 
            free (tmp->name); 
            free (tmp->author); 
            free (tmp); 
    } 
    }
    }