
#include "metodFromLr4.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

MusicalComposition* createMusicalComposition(char *name, char* autor, int year){
	MusicalComposition *temp=malloc(1 * sizeof(MusicalComposition));;
	temp->autor = autor;								
	temp->name = name;									
	temp->year = year;
	temp->next=NULL;
	temp->prev=NULL;									
	return temp;										
}
MusicalComposition* createMusicalCompositionList(char **arrayNames, char** arrayAutor, int* arrayYear, int n){	
	if (n >= 0){		
		if (n==1) return createMusicalComposition(arrayNames[0], arrayAutor[0], arrayYear[0]); 
		MusicalComposition *head = createMusicalComposition(arrayNames[0], arrayAutor[0], arrayYear[0]) ,
			*temp = createMusicalComposition(arrayNames[1], arrayAutor[1], arrayYear[1]), *current = head, *prevCurent=NULL;
		for (int i = 1; i <= n; i++){   
			current->prev = prevCurent;     
			if (i == n) break;			
			current->next = temp;			
			prevCurent = current;			
			current = temp;					
			temp = createMusicalComposition(arrayNames[i+1], arrayAutor[i+1], arrayYear[i+1]); 

		}
		return head; 

	}
	return NULL; 
}
void push(MusicalComposition* head,MusicalComposition* element){
	if (head != NULL){							
		for (; head->next != NULL; head = head->next); 
		head->next = element;       
		element->prev = head;
	}
	else{
		head = element;
	}
}
void removeEi(MusicalComposition* head, char* nameForRemove){  
	struct MusicalComposition* current = head,*prev,*next;			
	for (; current != NULL; current=current->next){			
		prev = current->prev;
		next = current->next;
		if (strcmp(current->autor, nameForRemove) == 0){   
			if (current != head){							
				prev->next = next;
				next->prev = prev;	
			}
			else{ 
				head = current->next;						
			}
			free(current);									
			break;											
		}
	}
}
int count(MusicalComposition* head){   
	int i;									
	for (i = 0; head!= NULL; head = head->next, i++);
	return i;
}
void print_names(MusicalComposition* head){   
	for (; head != NULL; head = head->next){
		printf("%s\n",head->name);
	}
}
