// Описание структуры MusicalComposition
typedef struct MusicalComposition{
 char* name;
 char* author;
 int year;
 struct MusicalComposition* prev;
 struct MusicalComposition* next;
} MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author, int year);

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

void push(MusicalComposition** head, MusicalComposition* element);

void removeEl(MusicalComposition** head, char* name_for_remove);

int count(MusicalComposition* head);

void print_names(MusicalComposition* head);

void free_list(MusicalComposition** list);

void insert_task(MusicalComposition* head, MusicalComposition* item1, MusicalComposition* item2);
