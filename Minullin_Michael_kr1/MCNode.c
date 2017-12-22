
#include "MCNode.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const int NAME_MAX_LENGTH       = 80;
const int AUTHOR_MAX_LENGTH     = 80;

MCNode* createMCNode(char* name, char* author, int year) {
    MCNode* node = (MCNode*)malloc(sizeof(MCNode));
    node->name = (char*)malloc((NAME_MAX_LENGTH + 1) * sizeof(char));
    strcpy(node->name, name);
    node->author = (char*)malloc((AUTHOR_MAX_LENGTH + 1) * sizeof(char));
    strcpy(node->author, author);
    node->year = year;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void freeMCNode(MCNode* node) {
    if (!node)
        return;
    free(node->name);
    free(node->author);
    free(node);
}

void printMCNode(MCNode* node) {
    if (!node)
        return;
    printf("Musical Composition:\nname:\t%s\nauthor:\t%s\nyear\t%d\n", node->name, node->author, node->year);
}