
#include "mcc.h"
#include "mc.h"

#include <stddef.h>
#include <stdlib.h>

void swaphalfs(MusicalComposition** mcl) {
    if (!(*mcl) || !((*mcl)->next))
        return;
    MusicalComposition* head = *mcl;
    int mclsize = count(head);
    int mclhalf = mclsize / 2;
    int i;
    MusicalComposition* midd = head;
    for (i = 0; i < mclhalf - 1; ++i)
        midd = midd->next;
    MusicalComposition* tail = midd;
    for (i = mclhalf; i < mclsize; ++i)
        tail = tail->next;
    MusicalComposition* temp = head->next;
    *mcl = midd->next;
    tail->next = head;
    head->prev = midd;
    midd->next->prev = NULL;
    midd->next = NULL;
    
}

void mcfree(MusicalComposition* mc) {
    if (!mc)
        return;
    free(mc->name);
    free(mc->author);
    free(mc);
}

void mclfree(MusicalComposition** mcl) {
    MusicalComposition* iter = *mcl;
    MusicalComposition* temp;
    while (iter) {
        temp = iter;
        iter = iter->next;
        mcfree(temp);
    }
}