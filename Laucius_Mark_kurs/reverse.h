#pragma once

void reverse(MusicalComposition** head)
{
	MusicalComposition* current = *head;
    MusicalComposition* pointer=NULL;
	while(current!=NULL)
	{   
		*head=current;
		pointer=current->next;
		current->next=current->previous;
		current->previous=pointer;
		current=current->previous;
	}	
}
