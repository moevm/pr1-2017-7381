#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"

void RemoveNode(MusicalComposition* node){
	if (node->prev){
	node->prev->next = node->next;
		}
	if (node->next){
	node->next->prev = node->prev;
	}
	free(node);
}
 

MusicalComposition* RemoveEvery(MusicalComposition** head, size_t number){

size_t counter = 0;
MusicalComposition* node = *head;
MusicalComposition* tmp;

while (node){
	if (++counter == number){
	counter = 0;
	tmp = node;
	node = node->next;
	RemoveNode(tmp);
	}
	else{
	node = node->next;
	}
}
	if (number == 1){
	*head = NULL;
}
	return *head;
}


MusicalComposition* createMusicalComposition(char* name, char* author,int year){

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


void push(MusicalComposition* head, MusicalComposition* element){
       
MusicalComposition* two_element = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	if ( head->next == NULL ){
	element->next = NULL;
	element->prev = head;
	head->next = element;
	return;
}
	two_element = head->next;

	while (two_element->next){
	two_element = two_element->next;
	}
	element->next = NULL;
	element->prev = two_element;
	two_element->next = element;
}


MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
	if ( n == 0 )
	return NULL;

MusicalComposition* head  = (MusicalComposition*)malloc(sizeof(MusicalComposition));

head->name = (char*)malloc(sizeof(char)*81);
head->author = (char*)malloc(sizeof(char)*81);

strcpy(head->name , array_names[0]);
strcpy(head->author , array_authors[0]);
head->year = array_years[0];

MusicalComposition* two_element;//не выделяю память malloc

	for ( int i = 1; i < n ; i++ ){
	two_element  = createMusicalComposition( array_names[i] , array_authors[i] , array_years[i] );
	push(head , two_element);
	}
return head;
}


void removeEl(MusicalComposition* head, char* name_for_remove){

	while(head){
	if(!strcmp(head->name,name_for_remove)){
	if(!(head->prev) && !(head->next)){ 
	free(head); 
	return;
}
	else if(!head->prev){
		*head = *(head->next);
		free(head->next->prev);
		head->next->prev = head;
		return;
		}
	else if(!head->next){ 
		head->prev->next = NULL; 
		free(head); 
		return;
		}
	else{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		free(head);
		return;
		}
	}
head = head->next;
	}
}


int count(MusicalComposition* head){

int i=1;
MusicalComposition* two_element = (MusicalComposition*)malloc(sizeof(MusicalComposition));
two_element = head->next;
	while (two_element != NULL){
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
