// MusicalComposition.cpp: 
#include <stdio.h>
#include "metodFromLr4.h"
#include <stdlib.h>

int main(){
	char **autor=malloc(5 * sizeof(char*)); autor[0] = "Rinat"; autor[1] = "Ctefaz Ctefaz"; 	autor[2] = "Lucia"; autor[3] = "Frida"; autor[4] = "Norman";
	int year[]={1945, 1965, 1915, 2015, 1945};
	int * years = year;
	char **names = malloc(5 * sizeof(char*)); names[0] = "Rinat"; names[1] = "Ctefaz Ctefaz"; 		names[2] = "Lucia"; names[3] = "Frida"; names[4] = "Norman";
	MusicalComposition *temp= createMusicalComposition("fsahsd","dhshjgf",1234);
	MusicalComposition *head = createMusicalCompositionList(names, autor, years,5);
	printf("%d",count(head));
	print_names(head);
	removeEi(head, "Ctefaz Ctefaz");
	printf("%d",count(head));
	print_names(head);
	return 0;
}
