#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "f.h"





int main(){
    int length;
    char string[80];
    printf("Введите количество элементов списка\n");
    scanf("%d", &length);  

    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);
    

    if (length==0)
        printf("Вы создали пустой список!\n");
    else{
    for (int i=0;i<length;i++)
    {   getchar();
        char name[80];
        char author[80];

        printf("Введите название музыкальной композиции\n");
        fgets(name, 80, stdin);
        printf("Введите имя автора композиции\n");
        fgets(author, 80, stdin);
        printf("Введите год создания музыкальной композиции\n");
        scanf( "%d", &years[i]);

        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

        strcpy(names[i], name);
        strcpy(authors[i], author);

    }
}
    





    MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
    char name_for_push[80];
    char author_for_push[80];
    int year_for_push;

    char name_for_remove[80];

    int choice,flag=0;
    int k;

    
  while ( flag == 0 )
   {   
       printf("Выберите, что вы хотите сделать со списком:\n");
           printf("0 - Добавить элемент в конец списка. \n");
           printf("1 - Удалить элемент с определённым названием композиций. \n");
           printf("2 - Вывести количество элементов в списке. \n");
           printf("3 - Вывести название всех музыкальных композиций из списка.\n");
           printf("4 - Удаить элемент, в поле 'автор' которого есть подстрока.\n");
           printf("5 - Выход.\n");
           
   
       scanf("%d" , &choice);
       switch(choice)
       {
            case 0:
                getchar();
                printf("Введите название добавляемой композиции\n" );
                fgets(name_for_push, 80, stdin);
                printf("Введите автора добавляемой композиции\n" );
                fgets(author_for_push, 80, stdin);
                printf("Введите год создания музыкальной композиции\n" );
                scanf( "%d", &year_for_push);
                (*strstr(name_for_push,"\n"))=0;
                (*strstr(author_for_push,"\n"))=0;
     MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
                getchar();
                push(head, element_for_push);
                break;

            case 1:
                getchar(); 
                printf("Введите название композиции, которое нужно убрать из списка.\n");
                fgets(name_for_remove, 80, stdin);
                (*strstr(name_for_remove,"\n"))=0;
                removeEl(&head, name_for_remove); 
                 break;

            case 2:
                k = count(head);
                printf("количество элементов в списке %d\n", k);
                 break;

            case 3:
                print_names(head);
                 break;

            case 4:
                getchar();
                printf("Введите подстроку для удаления\n");
                fgets(string,80,stdin);
                (*strstr(string,"\n"))=0;
                substring(&head,string);
                break;

            case 5: flag=1;
                break;

            default:printf("Неверный ввод\n");
        }
       
    }

    for (int i=0;i<length;i++){
        free(names[i]);
        free(authors[i]);
    }
    free(names);
    free(authors);
    free(years);

    return 0;

}