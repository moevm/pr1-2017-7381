#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "opt.h"

int main(){
    int length;
    printf("Enter the number of compositions:\n");
    scanf("%d\n", &length);  

    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

    MusicalComposition* head = NULL;
    MusicalComposition* element_for_push;

    if(length == 0){
        head == NULL;
        printf("List is empty!\n");
        exit(0);
    }
    else{

        for (int i=0;i<length;i++)
        {
            char name[80];
            char author[80];
            printf("Enter the name of composition:\n");
            fgets(name, 80, stdin);
            printf("Enter the name of author of the composition:\n");
            fgets(author, 80, stdin);
            printf("Enter release year:\n");
            fscanf(stdin, "%d\n", &years[i]);

            (*strstr(name,"\n"))=0;
            (*strstr(author,"\n"))=0;

            names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
            authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

            strcpy(names[i], name);
            strcpy(authors[i], author);

        }
    }
    head = createMusicalCompositionList(names, authors, years, length);
    
    char name_for_push[81];
    char author_for_push[81];
    int year_for_push;

    char name_for_remove[81];

    int opt = 0;
    int run = 1;
    while(run){
        printf("Enter the number of option:\n");
        scanf("%d\n", &opt);
        switch(opt){
            case 1:
                printf("Enter the name of comp:\n");
                fgets(name_for_push, 81, stdin);
                (*strstr(name_for_push,"\n"))=0;
                printf("Enter the name of author:\n");
                fgets(author_for_push, 81, stdin);
                (*strstr(author_for_push,"\n"))=0;
                printf("Enter the release year:\n");
                fscanf(stdin, "%d\n", &year_for_push);
                MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
                if(head == NULL)
                    head = element_for_push;
                else
                    push(head,element_for_push);
                break;
            case 2:
                if(head == NULL)
                    printf("List is empty!\n");
                else{
                    printf("Enter the name of composition,which you want do delete:\n");
                    fgets(name_for_remove, 81, stdin);
                    (*strstr(name_for_remove,"\n"))=0;
                    removeEl(&head, name_for_remove);
                }
                break;
            case 3:
                if(head == NULL)
                    printf("List is empty!\n");
                else{
                    printf("Deleting even composition...\n");
                    deleting(head);
                    print_names(head);
                }
                break;
            case 4:
                if(head == NULL)
                    printf("List is empty!\n");
                else
                    printf("The number of composition:%d\n",count(head));
                break;
            case 5:
                if(head == NULL)
                printf("List is empty!\n");
                else{
                    printf("Names of compositions:\n");
                    print_names(head);
                }
                break;            
            case 6:
                printf("Bye!\n");
                run = 0;
                break;

            default: printf("The entered data is incorrect,repeat again\n");
            }

    }

    for (int i=0;i<length;i++){
        free(names[i]);
        free(authors[i]);
    }
    free(names);
    free(authors);
    free(years);

    MusicalComposition* tmp = head->next;

    while(tmp != NULL)
        {
            tmp=tmp->next;
            free(tmp->prev);
        }
        free(tmp);
        free(head);
    return 0;

}