#pragma once

typedef struct Film
{
  int year;
  char* name;
  char* director;
  struct Film* next;
  struct Film* back;
}Film;

Film* makeFilm(char* name,char* director,int year)
{
  Film* make=(Film*)malloc(sizeof(Film));
    make->name = name;
    make->director = director;
    make->year = year;
    make->next = NULL;
    make->back = NULL;
    return make;
  
}

Film* makeFilmList(char** array_name,char** array_director,int* array_year,int n)
{
  Film* head = makeFilm(array_name[0], array_director[0], array_year[0]);
    Film* tmp;
    Film* prev=head;
    int i;
    for(i = 1; i < n; i++)
    {
        tmp = makeFilm(array_name[i], array_director[i], array_year[i]);
        tmp->back = prev;
        prev->next = tmp;
        prev = tmp;
    }
    return head;
}

int push(Film* head, Film* element, int n)
{
	if(head==NULL)
	{
		head=element;
		return n+1;
	}

   Film* tmp=head;

    while(tmp->next)
    {
        tmp=tmp->next;
    }
    element->next=NULL;
    element->back=tmp;
    tmp->next=element;
	return n+1;
}

int removeEl(Film** head, char* name_for_remove, int n)
{
    Film* tmp = *head;
    
    while (strcmp(tmp->name,name_for_remove)!=0)

    {
	if(!tmp->next)
		return n;
	tmp=tmp->next;
    }
        if(tmp->next!=NULL && tmp->back!=NULL)
        {
            tmp->next->back=tmp->back;
            tmp->back->next=tmp->next;
            tmp->next=NULL;
            tmp->back=NULL;
            free(tmp);
		
            return n-1;
        }
        if(tmp->back==NULL)
	{
		tmp=tmp->next;
		*head=tmp;
		tmp=tmp->back;
		tmp->next->back=NULL;
		tmp->next=NULL;
		
		free(tmp);
		
		return n-1;
	}
	if(tmp->next==NULL)
	{
		tmp->back->next=NULL;
		tmp->back=NULL;
		free(tmp);
		
		return n-1;
	}
	if(tmp->next==NULL && tmp->back==NULL)
	{
		free(tmp);
		
		return n-1;
	}
}


int count(Film* head)//кол-во фильмов
{
    int n=0;
    Film* tmp=head;
    while(tmp)
    {
        n++;
        tmp=tmp->next;
    }
    return n;
}

void print_names(Film* head)
{
    Film* tmp=head;
    while(tmp)
    {
        printf("%s\n", tmp->name);
        tmp=tmp->next;
    }
    
}
