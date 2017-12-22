#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
 

#define LEN 80
typedef struct Film
{
  int year;
  char* name;
  char* director;
  struct Film* next;
  struct Film* back;
}Film;

Film* makeFilm(char* name,char* director,int year);
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
Film* makeFilmList(char** array_name,char** array_director,int* array_year,int n);
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


void sort(Film* head,int n);
void sort(Film* head,int n)
{
  Film* half1;
   Film* half2;
  Film* tmp=head;
  int i=0;
  int j,c;
  for(i=0;i<n/2;i++)
  {
    tmp=tmp->next;
  }


    half1=tmp->back;//убыване
  half2=tmp;//возросане
  half2->back->next=NULL;
  half2->back=NULL;
   //возросане
  Film* a;
  Film* b;
  int year;
  char name[LEN];
  char director[LEN];
  int flag = 1;
  
  if(!half2)
  return;
  
  while(flag)
  {
    b=half2;
    a=half2->next;
    flag=0;
    
    while(a)
    {
      if((b->year)>(a->year))
      {
        strcpy(name, b->name);
        strcpy(b->name, a->name);
        strcpy(a->name, name);
        
        strcpy(director, b->director);
        strcpy(b->director, a->director);
        strcpy(a->director, b->director);
        
        year=b->year;
        b->year=a->year;
        a->year=year;
        
        flag=1;
      }
      b=b->next;
      a=a->next;
    }
  }


  
  
  
  //убыване
  flag=1;
  
while(flag)
  {
    b=half1;
    a=half1->back;
    flag=0;
    
    while(a)
    {
      if((b->year)>(a->year))
      {
        strcpy(name, b->name);
        strcpy(b->name, a->name);
        strcpy(a->name, name);
        
        strcpy(director, b->director);
        strcpy(b->director, a->director);
        strcpy(a->director, b->director);
        
        year=b->year;
        b->year=a->year;
        a->year=year;
        
        flag=1;
      }
      b=b->back;
      a=a->back;
    }
  }

  //соединение
  half1->next=half2;
  half2->back=half1;


}




int main()
{
  int i;
 int n;
  printf("кол-во фильмов\n");
    char c;
 scanf("%d%c", &n,&c);
 int year[80];
 char name[80];
 char director[80];

 int *year_array = malloc(n * sizeof(int));
  char **name_array = malloc(n * sizeof(char*));
  char **director_array = malloc(n * sizeof(char*));
for(i=0;i<n;i++){
      printf("struct: %d\n", i+1);
    char name[80];
    char director[80];
    char musor[80];
    
   
    printf("name: ");
    fgets(name,80,stdin);
    printf("director: ");
    fgets(director,80,stdin);
    fscanf(stdin, "%d\n",&year_array[i]);
    fgets(musor,80,stdin);
  
(*strstr(name,"\n"))=0;
(*strstr(director,"\n"))=0;
    
    name_array[i]=malloc(sizeof(char)*(strlen(name)+1));
    director_array[i]=malloc(sizeof(char)*(strlen(director)+1));
    
    strcpy(name_array[i],name);
    strcpy(director_array[i],director);
      
  }
  Film* tmp=makeFilmList(name_array,director_array,year_array, n);
  sort(tmp,n);

int h;
for(h=0;h<n;h++)
{
  printf("%s %s %d\n", tmp->name, tmp->director, tmp->year);
    tmp=tmp->next;
}

  while(tmp)
  {
    free(tmp->name);
    free(tmp->director);
    tmp=tmp->next;
    free(tmp->back->next);
    free(tmp->back);
  }
  for(i=0;i<n;i++)
  {
    free(name_array[i]);
    free(director_array[i]);
  }
  free(name_array);
  free(director_array);
  free(year_array);  
  free(tmp);
  
}
