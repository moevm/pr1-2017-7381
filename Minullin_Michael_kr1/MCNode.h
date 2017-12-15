
#ifndef __MCNode_H__
#define __MCNode_H__

extern const int NAME_MAX_LENGTH;
extern const int AUTHOR_MAX_LENGTH;

struct MCNode {
    char* name;
    char* author;
    int year;
    struct MCNode* prev;
    struct MCNode* next;
};

typedef struct MCNode MCNode;

MCNode* createMCNode(char*, char*, int);

void freeMCNode(MCNode*);

void printMCNode(MCNode*);

#endif