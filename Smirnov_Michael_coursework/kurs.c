#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "function.h"

//создание структуры

     void halfsort(MusicalComposition* head)
     {
         if(head==NULL)
         {
             printf("spisok pust\n");
             return;
         }
         MusicalComposition* tp;
         MusicalComposition* a;
         MusicalComposition* prom;
         int n=1,N,B,i,j,nonstop;
         int year;
         char name[81];
         char author[81];
         tp=head->next;
         n = count(head);
         if (n<=2) return;
         N=n/2;
         if (n%2==0) B=N-1;
             else B=N;

         for(i=N-1;i>=0;i--)
         {
             nonstop=1;
             tp=head;
             a=tp->next;
             for(j=0;j<N;j++)
             {
                 if (tp->year>a->year)
                 {
                     year=tp->year;
                     tp->year = a->year;
                     a->year = year;

                     strcpy(name,tp->name);
                     strcpy(tp->name,a->name);
                     strcpy(a->name,name);

                     strcpy(author,tp->author);
                     strcpy(tp->author,a->author);
                     strcpy(a->author,author);
                     nonstop=0;
                 }
                 tp=tp->next;
                 a=a->next;
             }
             if(nonstop==1) break;
         }

         prom=tp;

       for(i=N-1;i>=0;i--)
         {
             nonstop=1;
             tp=prom;
             a=tp->next;
             for(j=0;j<B;j++)
             {
                 if (tp->year<a->year)
                 {
                     year=tp->year;
                     tp->year = a->year;
                     a->year = year;

                     strcpy(name,tp->name);
                     strcpy(tp->name,a->name);
                     strcpy(a->name,name);

                     strcpy(author,tp->author);
                     strcpy(tp->author,a->author);
                     strcpy(a->author,author);
                     nonstop=0;
                 }
                 tp=tp->next;
                 a=a->next;
             }
             if(nonstop==1) break;
         }
     }
