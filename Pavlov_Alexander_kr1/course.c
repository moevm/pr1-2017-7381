
#include "course.h"

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void deleteEl(MusicalComposition** list, int n) {
    if (*list == NULL)
        return;
    MusicalComposition* iter = *list;
    while (iter) {
        if (strlen(iter->name) < n)
            removeEl(list, iter->name);
        iter = iter->next;
    }
}


void freeList(MusicalComposition** list){
	MusicalComposition* iter = *list;
	MusicalComposition* temp;
	if(!iter)
		return;
	while(iter){
		temp = iter;
		iter = iter->next;
		free(temp->name);
		free(temp->author);
		free(temp);
	}
}
