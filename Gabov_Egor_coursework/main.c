#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "main.h"


int main()
{
	int length;
	printf("введите сколько элементов будет содержать список:\n");
	scanf("%d" , &length );

	char** names = (char**)malloc(sizeof(char)*(length+1));	
	char** authors = (char**)malloc(sizeof(char)*(length+1));
	int* years = (int*)malloc(sizeof(int)*length);
	
	for ( int i=0; i<length; i++ )
	{
	
		names[i] = (char*)malloc(sizeof(char)*81);
                authors[i] = (char*)malloc(sizeof(char)*81);

		printf("введите название музыкальной композиции [%d]: " , i);
		scanf( "%s" , names[i] );
		//fgets( names[i] , 81 , stdin );	
	
		printf("введите автора музыкальной композиции [%d]: " , i);
		scanf( "%s" , authors[i] );
		//fgets( authors[i] , 81 , stdin );
	
		printf("введите год создания музыкальной композиции [%d]: " , i);
		scanf("%d" , &years[i]);
	}

    	register MusicalComposition* head = createMusicalCompositionList(names, authors, years, length); // если length 0 то голова NULL
	
	int choice;
	char* name_for_push = (char*)malloc(sizeof(char)*81);
        char* author_for_push = (char*)malloc(sizeof(char)*81);
        int year_for_push;
	char* name_for_remove = (char*)malloc(sizeof(char)*81);
	int c = 1;
	int first , last;
	MusicalComposition* element_for_push;
	
	while ( c == 1 )
	{	
		printf("выбирете операцию которую вы хотите совершить со списком:\n ");
        	printf("0 - добавить элемент в конец списка \n");
	        printf("1 - удалить элемент с совпадающим названием композиции \n");
        	printf("2 - вывести количество элементов в списке \n");
        	printf("3 - вывести название всех музыкальных композиций\n");
		printf("4 - вывести срез списка\n");
	
		scanf("%d" , &choice);
		switch(choice)
		{
			case 0: 
				printf("введите название добавляемой композиции: ");
        			scanf("%s" , name_for_push );		
	
				printf("введите автора добавляемой композиции: ");
       				scanf("%s" , author_for_push );	 	
	
				printf("введите год создания добавляемой композиции: ");
				scanf("%d", &year_for_push);

        			element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
				push( head , element_for_push ); 
				break;

			case 1:
				printf("введите название композиции которую нужно убрать из списка: ");
				scanf( "%s" , name_for_remove );
				removeEl(head, name_for_remove); 
				break;

			case 2: 
				printf("количество элементов в списке: %d \n", count(head));
				break;
	
			case 3:
				print_names(head);
				break;
			
			case 4:	
				printf("введите номер начального элемента среза списка: ");	
				scanf("%d" , &first);
				
				printf("введите номер конечного элемента среза списка: ");
                                scanf("%d" , &last );

				print_srez_spiska( head , first , last );
				break;

		
			default: printf("введенно неправильное число :( \n");
		}
		
		printf("введите [1] если хотите продолжить и любое другое число для выхода: ");
		scanf("%d" , &c );
	}


    	for (int i=0;i<length;i++)
	{
    	    free(names[i]);
    	    free(authors[i]);
    	}
    	free(names);
    	free(authors);
    	free(years);
	free(name_for_push);
	free(author_for_push);
	free(name_for_remove);
		
	for ( MusicalComposition* temp = head; temp -> next ; temp = temp->next )
	{
		free(temp->name);
		free(temp->author);
		free(temp);
	}		
	
    	return 0;

}











