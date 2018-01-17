#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include "fnctns.h"
#include "sort.h"
 
#define LEN 80









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
    char cleaner[10];
    
   
    printf("name: ");
    fgets(name,80,stdin);
    printf("director: ");
    fgets(director,80,stdin);
	printf("Год выпуска: ");
    fscanf(stdin, "%d\n",&year_array[i]);
	fgets(cleaner,10,stdin);
   
  
(*strstr(name,"\n"))=0;
(*strstr(director,"\n"))=0;
    
    name_array[i]=malloc(sizeof(char)*(strlen(name)+1));
    director_array[i]=malloc(sizeof(char)*(strlen(director)+1));
    
    strcpy(name_array[i],name);
    strcpy(director_array[i],director);
      
  }
  Film* head=makeFilmList(name_array,director_array,year_array, n);
  
  
  char cleaner[10];  
  int choose=0;
  char clean_buf;
  char name_for_push[LEN];
  char director_for_push[LEN];
  int year_for_push;
  char name_for_rem[LEN]; 
  printf("1 - добавить фильм в список\n");
  printf("2 - удалить фильм из списка\n");
  printf("3 - вывести кол-во фильмов в списке\n");
  printf("4 - вывести названия фильмов\n");
  printf("5 - отсортировать 1-ую половину списка по убыванию, 2-ую по возростанию\n");
  printf("6 - закончить программу\n");
  
  while(choose!=6)
 {
	  scanf("%d%c",&choose,&clean_buf);
	  
				if(choose<1 || choose>6)
				{
					printf("введите корректную задачу\n");
					continue;
				}
		switch(choose)
		{
			case 1:
					
					
					printf("Введите названия фильма\n");
					fgets(name_for_push, 80, stdin);
					printf("Введите имя режиссера\n");
					fgets(director_for_push, 80, stdin);
					printf("Ввеите год выпуска\n");
					fscanf(stdin, "%d\n", &year_for_push);
					fgets(cleaner,10,stdin);
					(*strstr(name_for_push,"\n"))=0;
					(*strstr(director_for_push,"\n"))=0;
					Film* element_for_push=makeFilm(name_for_push,director_for_push,year_for_push);
					n=push(head,element_for_push,n);
					break;
			case 2:
					
					fgets(cleaner,10,stdin);
					printf("Какой фильм удалить?\n");
					fgets(name_for_rem,80,stdin);
					(*strstr(name_for_rem,"\n"))=0;
					n=removeEl(&head,name_for_rem,n);
					break;
			case 3:
					printf("%d",count(head));
					break;
			case 4:
					print_names(head);
					break;
			case 5:
					sort(head, n);
					break;
		}
			
					
}
Film* tmp=head;
while(tmp->next!=NULL)
{
	tmp=tmp->next;
	tmp->back->next=NULL;
	tmp->back=NULL;
}	
free(tmp);
free(head);
for(i=0;i<n;i++)
{
	free(name_array[i]);
	free(director_array[i]);
}
free(name_array);
free(director_array);
free(year_array);
  
}
