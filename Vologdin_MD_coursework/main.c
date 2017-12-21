#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "func.h"
#include "year.h"
int main(){
    printf("Number of songs=");
    int length;
    scanf("%d", &length);
    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

    for (int i=0;i<length;i++)
    {
        printf("%d\n",i+1);
        char name[80];
        char author[80];
        printf("Song name: ");
        getchar();
        fgets(name, 80, stdin);
        printf("Author: ");
        fgets(author, 80, stdin);
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
        printf("What do you want?\n");
        printf("1-Amount of elements\n");
        printf("2-Add an item to the end of the list\n");
        printf("3-Delete the item with the name you typed\n");
        printf("4-Delete all items in the list, in which the year is less than the one you type\n");
        printf("5-Show list\n");

        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Count = %d\n",count(head));
            break;
        case 2:

            printf("Song name: ");
            getchar();
            fgets(name_for_push, 80, stdin);

            printf("Author: ");
            fgets(author_for_push, 80, stdin);

            printf("Year: ");
            fscanf(stdin, "%d", &year_for_push);

            (*strstr(name_for_push,"\n"))=0;
            (*strstr(author_for_push,"\n"))=0;
            head = push(head,createMusicalComposition(name_for_push,author_for_push,year_for_push));
            break;
        case 3:
            printf("Enter the name\n");
            getchar();
            fgets(name_for_remove,80,stdin);
            (*strstr(name_for_remove,"\n"))=0;
            head = removeEl(head,name_for_remove);
            break;
        case 4:
            printf("Enter the year\n");
            scanf("%d",&year_for_remove);
            head=remove_all_year(head,year_for_remove);
            break;
        case 5:
            if (head)
                print_names(head);
            else
                printf("The list is empty!\n");
            break;
        default:
            printf("WRONG! Please try again\n");
        }
        printf("Contnue? Yes-1 No-0\n");
        scanf("%d",&da);
    }
    for (int i=0;i<length;i++){
        free(names[i]);
        free(authors[i]);
    }
    free(names);
    free(authors);
    free(years);

    clear_list(head);
    return 0;

}
