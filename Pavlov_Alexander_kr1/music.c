
#include "music.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
    MusicalComposition* newmc = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    newmc->name = (char*)malloc(81 * sizeof(char));
    strcpy(newmc->name, name);
    newmc->author = (char*)malloc(81 * sizeof(char));
    strcpy(newmc->author, author);
    newmc->year = year;
    newmc->next = NULL;
    newmc->prev = NULL;
    return newmc;
}

void push(MusicalComposition** head, MusicalComposition *element)
{
    if (*head == NULL) {
        *head = element;
        return;
    }
    MusicalComposition* iter;
    for (iter = *head; iter->next; iter = iter->next);
    element->prev = iter;
    iter->next = element;
}

void removeEl(MusicalComposition** list, char* name_for_remove){
	if (*list == NULL)
         return;
     MusicalComposition* iter = *list;
     MusicalComposition* tmp;
     while (iter != NULL) {
         tmp = iter;
         iter = iter->next;
         if (strcmp(tmp->name, name_for_remove) == 0){
				if (tmp->next == NULL && tmp->prev == NULL) {
       				free(tmp);
 					*list = NULL;
 				}
       			else if (tmp->next == NULL) {
         			tmp = tmp->prev;
         			free(tmp->next);
         			tmp->next = NULL;
       			}
       			else if (tmp->prev == NULL){ 
       				*list = tmp->next;
       				tmp = tmp->next;
        			free(tmp->prev);
 					tmp->prev = NULL;
       			}

       			else {                        
       				tmp->prev->next = tmp->next;
       				tmp->next->prev = tmp->prev;
       				free(tmp);
       			}
       			return;
		 }
 }
 }
int count(MusicalComposition* list)
{
     MusicalComposition* iter = list;
     int n = 0;
     while (iter)
     {
         n++;
         iter = iter->next;
     }
     return n;
 }

void print_names(MusicalComposition* list) {
    MusicalComposition* iter = list;    
 	if (!iter)
 		printf("Список пустой.\n");
    for(; iter!=NULL ; iter = iter->next)
          printf("%s\n", iter->name);
 }
