
#include "MCNode.h"
#include "MCList.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    MCList* playlist = createMCList();

    MCNode* song_1;
    MCNode* song_2;
    MCNode* song_3;

    char name[NAME_MAX_LENGTH];
    char author[AUTHOR_MAX_LENGTH];
    int year;
    
    char query;
    
    printf("\nInput query:\n1: Insertion song at begin of playlist\n2: Insertion song at end of playlist\n3: Removing song from begin of playlist;\n4: Removing song from end of playlist;\n5: Printing a playlist;\n6: Printing count of songs in playlist;\n7: Theme of my course work;\nq: Quit;\n");
    do {
        printf("> ");
        scanf(" %c", &query);
        switch (query) {
        case '1':
            printf("<name> <author> <year>\n");
            scanf("%80s %80s %d", name, author, &year);
            insert_head(playlist, createMCNode(name, author, year));
            break;
        case '2':
            printf("<name> <author> <year>\n");
            scanf("%80s %80s %d", name, author, &year);
            insert_tail(playlist, createMCNode(name, author, year));
            break;
        case '3':
            remove_head(playlist);
            break;
        case '4':
            remove_tail(playlist);
            break;
        case '5':
            printMCList(playlist);
            break;
        case '6':
            printf("%d\n", nodes_count(playlist));
            break;
        case '7':
            printf("1. <name> <author> <year>\n");
            scanf("%s %s %d", name, author, &year);
            song_1 = createMCNode(name, author, year);
            printf("2. <name> <author> <year>\n");
            scanf("%s %s %d", name, author, &year);
            song_2 = createMCNode(name, author, year);
            printf("3. <name> <author> <year>\n");
            scanf("%s %s %d", name, author, &year);
            song_3 = createMCNode(name, author, year);
            insert_midd(playlist, song_1, song_2, song_3);
            break;
        case 'q':
            break;
        default:
            printf("Unknown query; Repeat input:\n");
        }
    } while (query != 'q');

    freeMCList(playlist);

    return 0;
}