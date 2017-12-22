
#include "MCNode.h"
#include "MCList.h"

#include <stdlib.h>

MCList* createMCList() {
    MCList* list = (MCList*)malloc(sizeof(MCList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void freeMCList(MCList* list) {
    if (!list)
        return;
    if (!list->head && !list->tail) {
        free(list);
        return;
    }
    if (list->head == list->tail)
        freeMCNode(list->head);
    else {
        MCNode* iter;
        while (list->head) {
            iter = list->head;
            list->head = list->head->next;
            freeMCNode(iter);
        }
    }
    free(list);
}

MCNode* insert_head(MCList* list, MCNode* node) {
    if (!list || !node)
        return NULL;
    if (!list->head && !list->tail) {
        list->head = list->tail = node;
        list->head->next = list->tail;
        list->tail->prev = list->head;
        return list->head;
    }
    if (list->head == list->tail) {
        list->head = node;
        list->head->next = list->tail;
        list->tail->prev = list->head;
    }
    else {
        list->head->prev = node;
        list->head->prev->next = list->head;
        list->head = node;
    }
    return list->head;
}

MCNode* insert_midd(MCList* list, MCNode* node_1, MCNode* node_2, MCNode* node_3) {
    if (!list || !node_1 || !node_2 || !node_3)
        return NULL;
    node_1->next = node_2;
    node_2->prev = node_1;
    node_2->next = node_3;
    node_3->prev = node_2;
    if (!list->head && !list->tail) {
        node_1->prev = NULL;
        list->head = node_1;
        list->tail = node_3;
        node_3->next = NULL;
        return node_1;
    }
    if (list->head == list->tail) {
        node_1->prev = NULL;
        list->head = node_1;
        list->tail->prev = node_3;
        node_3->next = list->tail;
    }
    else {
        int midd = nodes_count(list) >> 1;
        MCNode* iter = list->head;
        for (int i = 1; i < midd; ++i)
            iter = iter->next;
        MCNode* iter_next = iter->next;
        node_1->prev = iter;
        iter->next = node_1;
        iter_next->prev = node_3;
        node_3->next = iter_next;
    }
    return node_1;
}

MCNode* insert_tail(MCList* list, MCNode* node) {
    if (!list || !node)
        return NULL;
    if (!list->head && !list->tail) {
        list->tail = list->head = node;
        list->tail->prev = list->head;
        list->head->next = list->tail;
        return list->tail;
    }
    if (list->head == list->tail) {
        list->tail = node;
        list->head->next = list->tail;
        list->tail->prev = list->head;
    }
    else {
        list->tail->next = node;
        list->tail->next->prev = list->tail;
        list->tail = node;
    }
    return list->tail;
}

MCNode* remove_head(MCList* list) {
    if (!list || !list->head)
        return NULL;
    if (list->head == list->tail) {
        freeMCNode(list->head);
        return list->head = list->tail = NULL;
    }
    list->head = list->head->next;
    freeMCNode(list->head->prev);
    list->head->prev = NULL;
    return list->head;
}

MCNode* remove_tail(MCList* list) {
    if (!list || !list->tail)
        return NULL;
    if (list->head == list->tail) {
        freeMCNode(list->tail);
        return list->tail = list->head = NULL;
    }
    list->tail = list->tail->prev;
    freeMCNode(list->tail->next);
    list->tail->next = NULL;
    return list->tail;
}

int nodes_count(MCList* list) {
    if (!list)
        return 0;
    if (!list->head && !list->tail)
        return 0;
    if (list->head == list->tail)
        return 1;
    int count = 1;
    MCNode* iter;
    for (MCNode* iter = list->head; iter != list->tail; iter = iter->next)
        count++;
    return count;
}

void printMCList(MCList* list) {
    if (!list)
        return;
    for (MCNode* iter = list->head; iter != list->tail; iter = iter->next)
        printMCNode(iter);
    printMCNode(list->tail);
}