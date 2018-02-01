#include "metodFromLr4.h"
#include "string.h"
#include "stdlib.h"

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

