#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

MusicalComposition* remove_all_year(MusicalComposition *list, int n)
{
    MusicalComposition *temp;
    MusicalComposition *head;
    head=list;
    while(head)
    {
        if (head->year < n)
        {
            temp=head;
            if (temp->prev)
                temp->prev->next=temp->next;

            else
            {
                if (temp->next)
                    temp->next->prev=NULL;
                free(temp->name);
                free(temp->author);
                list=list->next;
                head=head->next;
                free(temp);
                temp=NULL;
                continue;
            }
            if (temp->next)
                temp->next->prev=temp->prev;
            head=temp->next;
            free(temp->name);
            free(temp->author);
            free(temp);
            temp=NULL;
        }
        else
            head=head->next;
   }
    return list;
}
