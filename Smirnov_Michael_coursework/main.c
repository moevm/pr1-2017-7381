#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "function.h"





int main()
 {
   printf("Number of songs=");

     int length; int i;
     scanf("%d", &length);

     char** names = (char**)malloc(sizeof(char*)*length);
     char** authors = (char**)malloc(sizeof(char*)*length);
     int* years = (int*)malloc(sizeof(int)*length);

     for ( i=0;i<length;i++)
     {
         printf("%d\n",i+1);
         char name[81];
         char author[81];
         printf("Song name: ");
         getchar();
         fgets(name, 81, stdin);
         printf("Author: ");
         fgets(author, 81, stdin);
         printf("Year: ");

         fscanf(stdin, "%d", &years[i]);
         (*strstr(name,"\n"))=0;
         (*strstr(author,"\n"))=0;

         names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
         authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
         strcpy(names[i], name);
         strcpy(authors[i], author);

     }
     printf("\n");
     MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
     int da=1;
     int choice = 0;
     int year_for_remove=0;
     char *name_for_push=(char*)malloc(sizeof(char*) * 81);
     char *author_for_push=(char*)malloc(sizeof(char*) * 81);
     int year_for_push=0;
     char *name_for_remove = (char*)malloc(sizeof(char)*81);
     while (da)
     {
         printf("Choose function\n");
         printf("1-Amount of elements\n");
         printf("2-Add element to end\n");
         printf("3-Sort and show list\n");
         printf("4-Exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
         case 1:
             printf("Count = %d\n",count(head));
             break;
         case 2:

             printf("Song name: ");MusicalComposition* remove_all_year(MusicalComposition *list, int n);
             getchar();
             fgets(name_for_push, 81, stdin);

             printf("Author: ");
             fgets(author_for_push, 81, stdin);

             printf("Year: ");
             fscanf(stdin, "%d", &year_for_push);

             (*strstr(name_for_push,"\n"))=0;
             (*strstr(author_for_push,"\n"))=0;
             head = push(head,createMusicalComposition(name_for_push,author_for_push,year_for_push));
             break;
         case 3:
             halfsort(head);
                print_names(head);

             break;
             case 4: return 0;
         default:
             printf("WRONG! Please try again\n");
         }
     }
     for ( i=0;i<length;i++){
         free(names[i]);
         free(authors[i]);
     }
     free(names);
     free(authors);
     free(years);
     return 0;
 }
