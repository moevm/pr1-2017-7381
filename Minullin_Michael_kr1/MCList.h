
#ifndef __MCLIST_H__
#define __MCLIST_H__

struct MCList {
    MCNode* head;
    MCNode* tail;
};

typedef struct MCList MCList;

MCList* createMCList();
void freeMCList(MCList*);

MCNode* insert_head(MCList*, MCNode*);
MCNode* insert_midd(MCList*, MCNode*, MCNode*, MCNode*);
MCNode* insert_tail(MCList*, MCNode*);

MCNode* remove_head(MCList*);
MCNode* remove_tail(MCList*);

int nodes_count(MCList*);

void printMCList(MCList*);

#endif