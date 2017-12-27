typedef struct MusicalComposition
	{
	char* name;
	char* author;
	int year;
	struct MusicalComposition *next;
	struct MusicalComposition *previous;
	}MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author,int year)
	{
	MusicalComposition* song=(MusicalComposition*)malloc(sizeof(MusicalComposition));
	song->name=name;
	song->author=author;
	song->year=year;
	song->next=NULL;
	song->previous=NULL;
	return song;
	}
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
	{
	MusicalComposition* head=createMusicalComposition(array_names[0],array_authors[0],array_years[0]);
	MusicalComposition* list=head;
	int i;
	for(i=1; i<n; i++)
		{
		list->next=createMusicalComposition(array_names[i],array_authors[i],array_years[i]);
		list->next->previous=list;
		list=list->next;
		}
	return head;
	}

void push(MusicalComposition* head, MusicalComposition* element)
	{
	MusicalComposition* list=head;
   	while (list->next!=NULL)
        list=list->next;
    	list->next=element;
    	element->previous=list;
	}

void removeEl(MusicalComposition* head, char* name_for_remove)
	{
	MusicalComposition* list=head;
	while(list->next!=NULL)
	{
		if(strcmp(name_for_remove, list->name)==0)
		{
		list->next->previous=list->previous;
		list->previous->next=list->next;
		}
	list=list->next;
	}
	}

MusicalComposition* swap(MusicalComposition* head)
	{
	MusicalComposition* list=head;
	if(head!=NULL)
	{
	if(list->next==NULL && list->previous==NULL)
	return head;
	 list->next->previous=list->previous;
                list->previous=list->next;
                list->next=list->next->next;
                list->previous->next=list;
                if(list->next!=NULL)
                        {
                        list->next->previous=list;
                list=list->next;
                        }
	head=head->previous;
	}
	while(list->next!=NULL && list!=NULL)
		{
		list->previous->next=list->next;
		list->next->previous=list->previous;
		list->previous=list->next;
		list->next=list->next->next;
		list->previous->next=list;
		if(list->next!=NULL)
			{
			list->next->previous=list;
		list=list->next;
			}
		else
		break;
		}

	return head;
	}

int count(MusicalComposition* head)
	{
	MusicalComposition* list=head;
	int i=0;
	while(list!=NULL)
	{
	i++;
	list=list->next;
	}
	return i;
	}


void print_names(MusicalComposition* head)
	{
	MusicalComposition* list=head;
	while(list!=NULL)
	{
	printf("%s\n", list->name);
	list=list->next;
	}
	}


