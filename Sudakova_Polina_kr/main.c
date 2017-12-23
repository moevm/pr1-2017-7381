// MusicalComposition.cpp: 
#include <stdio.h>
#include "courseWork.h"
#include <stdlib.h>

void print_name(MusicalComposition *t4){
	if (t4 != NULL){
		for (; t4->prev != NULL; t4 = t4->prev){
}
		for (; t4 != NULL; t4 = t4->next){
			printf("%s\n", t4->name);
		}
	}

}
int main(){
	char **autor=malloc(5 * sizeof(char*)); autor[0] = "Rinat"; autor[1] = "Ctefaz Ctefaz"; autor[2] = "Lucia"; autor[3] = "Frida"; autor[4] = "Norman";
	int year[]={1945, 1965, 1915, 2015, 1945};
	int * years = year;
	char **names = malloc(5 * sizeof(char*)); names[0] = "Rinat"; names[1] = "Ctefaz Ctefaz"; names[2] = "Lucia"; names[3] = "Frida"; names[4] = "Norman";
	MusicalComposition *t1,*t2,*t3,*t4;
	t1 = createMusicalCompositionList(names, autor, years, 5);
	t2 = createMusicalComposition("fsahsd", "dhshjgf", 1234);
	t3 = createMusicalCompositionList(names, autor, years, 3);
	t4 = NULL;
	printf("%d\n",1);
	print_name(t1);
	printf("%d\n",2);
	print_name(t2);
	printf("%d\n",3);
	print_name(t3);
	printf("%d\n",4);
	print_name(t4);	
	addFromHeadAll4Element(t1, t2, t3, t4);
	printf("Result\n");
	print_name(t1);
	return 0;
}
