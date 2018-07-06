typedef struct MusicalComposition{  
	char *name;		
	char *autor;		
	int year;						
	struct MusicalComposition* next;
	struct MusicalComposition* prev;		
}MusicalComposition;
