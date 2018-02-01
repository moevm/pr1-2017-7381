#include <stddef.h>
#include "courseWork.h"
void addHead(MusicalComposition *current, MusicalComposition *temp){
	if (current==NULL) {					
		current = temp; return;
	}
	if (temp==NULL) {					
		return;
	}
	for (; current->prev!=NULL; current = current->prev);
	for (; temp->next!=NULL; temp = temp->next);			
	temp->next = current;				
	current->prev = temp;		
}

void addFromHeadAll4Element(MusicalComposition* head, MusicalComposition* t1, MusicalComposition* t2, MusicalComposition* t3){
	addHead(head, t1);
	addHead(head, t2);
	addHead(head, t3);
}

