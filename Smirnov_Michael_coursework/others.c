#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "function.h"

//создание структуры


MusicalComposition* createMusicalComposition(char* name, char* author,int year)
    {
    MusicalComposition* addmusic=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    addmusic->name = name;
    addmusic->author = author;
    addmusic->year=year;
    addmusic->next=NULL;
    addmusic->prev=NULL;
    return addmusic;
    }

    //работа со списком


   MusicalComposition* push(MusicalComposition* head, MusicalComposition* element)
 {
         if (!head)
         {
             head=element;
             return head;
         }
         if ( head->next == NULL )
         {
                 element->next = NULL;
                 element->prev = head;
                 head->next = element;
                 return head;
         }

         MusicalComposition *temp = head->next;

         while (temp->next)
         {
                 temp = temp->next;
         }

         element->next = NULL;
         element->prev = temp;
         temp->next = element;
         return head;
 }

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
    {
        int g;
        if (n==0) return NULL;
        MusicalComposition *head=createMusicalComposition(array_names[0],array_authors[0], array_years[0]);
        MusicalComposition *tp=(MusicalComposition*)malloc(sizeof(MusicalComposition));
                                             for(g=1;g<n;g++)
                     {
                         tp=createMusicalComposition(array_names[g],array_authors[g],array_years[g]);
                         push(head,tp);
                     }
                        return head;
     }

 int count(MusicalComposition* head)
     {
        int n=1;
        MusicalComposition* tp=(MusicalComposition*)malloc(sizeof(MusicalComposition));
        tp = head->next;
        while (tp)
        {
                tp = tp->next;
                n++;

        }
        return n;
    }
    void print_names(MusicalComposition* head)
            {
          if(head== NULL) return;
          MusicalComposition *tp=head;
           do {
               printf("%d - %s - %s\n",tp->year,tp->name,tp->author);
               tp = tp->next;
           } while (tp !=NULL);
             }
