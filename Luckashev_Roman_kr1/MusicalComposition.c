#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "MusicalComposition.h"

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author, int year){
	MusicalComposition* my_composition = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	my_composition->name = (char*)calloc(81, sizeof(char));
	strncpy(my_composition->name, name, 80);
	my_composition->author = (char*)calloc(81, sizeof(char));
	strncpy(my_composition->author, author, 80);
	my_composition->year = year;
	my_composition->next = NULL;
	my_composition->prev = NULL;
	return my_composition;
}


MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
	if(!n) return NULL;
        MusicalComposition* List = createMusicalComposition(*array_names, *array_authors, *array_years);
	for(int i = 1; i < n; i++){
        MusicalComposition* Next = createMusicalComposition(*(array_names+i), *(array_authors+i), *(array_years+i));
	push(&List, Next);
	}
return List;
}

void push(MusicalComposition** head, MusicalComposition* element){
	if(!(*head)){
	 *head = element;
	 return;
	}
	MusicalComposition* temp = *head;
	while(temp->next){
	 temp = temp->next;
	}
	element->prev = temp;
	element->next = NULL;
	temp->next = element;
}

void removeEl(MusicalComposition** head, char* name_for_remove){
  MusicalComposition* temp = *head;
  while((*head)){
	if(!strcmp((*head)->name, name_for_remove)){
	 if(!((*head)->prev) && !((*head)->next)){ free_list(head); return; }
	 if(!((*head)->prev)){
	  *head = (*head)->next; ((*head)->prev)->next = NULL; free_list(&((*head)->prev)); (*head)->prev = NULL; return;
	 }
	 if(!((*head)->next)){
	  (*head)->prev->next = NULL; free_list(head); *head = temp; return;
	 }
	 (*head)->prev->next = (*head)->next;
	 (*head)->next->prev = (*head)->prev;
	 (*head)->next = NULL;
	 free_list(head);
	 *head = temp;
	 return;
	}
  (*head) = (*head)->next;
  }
}

int count(MusicalComposition* head){
	int i = 0;
	while(head){
	 i++;
	 head = head->next;
	}
	return i;
}

void print_names(MusicalComposition* head){
while(head){
  printf("%s\n", head->name);
  head = head->next;
 }
}

void free_list(MusicalComposition** list){
	if(!(*list)) return;
	while(((*list)->next)){
	*list = (*list)->next;
	free(((*list)->prev)->name);
        free(((*list)->prev)->author);
	free((*list)->prev);
	(*list)->prev = NULL;
	}
        free((*list)->name);
        free((*list)->author);
        free((*list));
	(*list) = NULL;
}

void insert_task(MusicalComposition* head, MusicalComposition* item1, MusicalComposition* item2){
	int i = 0;
	while(head){
	 if(i == 1){
	  i = -1;
	  MusicalComposition* insert1 = createMusicalComposition(item1->name, item1->author, item1->year);
	  insert1->prev = head;
	  MusicalComposition* insert2 = createMusicalComposition(item2->name, item2->author, item2->year);
	  insert1->next = insert2;
	  insert2->prev = insert1;
	  insert2->next = head->next;
	  if(head->next) head->next->prev = insert2;
	  head->next = insert1;
	  head = head->next->next;
	 }
	 i++;
	 head = head->next;
	}
}
