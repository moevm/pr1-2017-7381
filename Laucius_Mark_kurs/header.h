#pragma once


typedef struct MusicalComposition
{
    char* name;
    char* author;
    int year;
    struct MusicalComposition *next;
    struct MusicalComposition *previous;
}MusicalComposition;


MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{

    MusicalComposition* music = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    music->name = name;
    music->author = author;
    music->year = year;
    music->next = NULL;
    music->previous = NULL;
    return music;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
  MusicalComposition* head = NULL;
  if(n>0){
    head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition* current;
    MusicalComposition* previous_el=head;
    int i;
    for(i = 1; i < n; i++)
    {
        current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        current->previous = previous_el;
        previous_el->next = current;
        previous_el = current;
    }
  }
    return head;
}

void push(MusicalComposition** head, MusicalComposition* element)
{
    MusicalComposition* current = *head;
    if(*head==NULL)
	*head=element;
    else{
        while(current->next)
	{
            current=current->next;
	}
        current->next=element;
        element->previous=current;
    }
}

void removeEl(MusicalComposition** head, char* name_for_remove)
{
    MusicalComposition* current = *head;
    MusicalComposition* pointer=NULL;
    while(current)
    {
        if(strcmp(current->name, name_for_remove) == 0)
        {	//удаление элемента без neхt и previous
	    if(current->next == NULL && current->previous == NULL){
                 free(*head);
                 *head=NULL;
		 head=NULL;
                 return;
            }
			//удаление элемента с neхt и previous
            if(current->next != NULL && current->previous != NULL)
            {
            	pointer=current;
                current->previous->next = current->next;
                current->next->previous = current->previous;
                current=current->next;
                free(pointer);
                pointer=NULL;
                continue;
            }
            //удаление элемента без neхt
	    if(current->next == NULL)
            {
                current->previous->next = NULL;
                free(current);
                current=NULL;
                return;
            }
            //удаление элемента без previous
	    else if(current->previous == NULL)
            {
            	pointer=current;
                current->next->previous = NULL;
                *head = current->next;
                current=*head;
                free(pointer);
                pointer=NULL;
                continue;
	    }
	}
	current = current->next;

    }

}

int count(MusicalComposition* head)
{
    MusicalComposition* current = head;
    int n = 0;
    while (current)
    {
        n++;
        current = current->next;
    }
    return n;
}

void print_names(MusicalComposition* head)
{
    MusicalComposition* current = head;
    while (current)
    {
        printf("%s\n", current->name);
        current = current->next;
    }
}
void delete_list(MusicalComposition** head)
{
    while((*head)->next)
    {   
		(*head)=(*head)->next;
        free((*head)->previous);
        
    }
    free(*head);
    *head=NULL;
    head=NULL;
}
