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
    MusicalComposition* head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
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
    return head;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
    MusicalComposition* current = head;
    while(current->next)
        current=current->next;
    current->next=element;
    element->previous=current;
}

void removeEl(MusicalComposition* head, char* name_for_remove)
{
    MusicalComposition* current = head;
    //MusicalComposition* pointer;
    while(current->next)
    {
        if(strcmp(current->name, name_for_remove) == 0)
        {
            //pointer=current;
            if(current->next != NULL && current->previous != NULL)
            {
                current->previous->next = current->next;
                current->next->previous = current->previous;
            }
            else if(current->next == NULL)
            {
                current->previous->next = NULL;
            }
            else if(current->previous == NULL)
            {
                
                current->next->previous = NULL;
                head = current->next;
            }
            free(current);
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
