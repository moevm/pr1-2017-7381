
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


// Описание структуры MusicalComposition
typedef struct MusicalComposition{
    char name[80];
    char author[80];
    char name_add[80];
    int year;
    struct MusicalComposition* next;
    struct MusicalComposition* prev;
}MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* autor,int year){//ghghgghhg
    MusicalComposition* mus=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    int i;
    for(i=0;i<80;i++){
        mus->name[i]=name[i];
        mus->author[i]=autor[i];
    }
    mus->year=year;
    mus->next=NULL;
    mus->prev=NULL;
    return mus;
}

// Функции для работы со списком MusicalComposition

MusicalComposition* push(MusicalComposition* head, MusicalComposition* element){//fdfdffdfd
    if(head==NULL){
        return element;
    }

    if(head->next==NULL){
        head->next=element;
        element->prev=head;
        return head;
    }
    push(head->next,element);

    return head;
}



MusicalComposition* createMusicalCompositionList(MusicalComposition* head,char* array_names, char* array_authors, int array_years){
    
    
        MusicalComposition* mus=createMusicalComposition(array_names,array_authors,array_years);
        head = push(head,mus);

    
    return head;
}

MusicalComposition* head_del(MusicalComposition* head){ //dssdfdsfdsf
    MusicalComposition* newHead;
    if(head==NULL)
        return NULL;
    newHead= head->next;
    newHead->prev=NULL;
    free(head);
    return newHead;
}

MusicalComposition* tail_add(MusicalComposition* head,MusicalComposition* list){
    if(head->next!=NULL){//sadsa
        MusicalComposition* p=head->next;
        p->prev=list;
        list->next=p;
        return list;
    }
    head->next=NULL;
    head->prev=list;
    list->next=head;
    return list;
      
    
}

MusicalComposition* tail_del(MusicalComposition* head){//sadsadsda
    if(head==NULL)
        return NULL;
    if(head->next==NULL){
        head->prev->next=NULL;
        free(head);
    }
    tail_del(head->next);
    return head;
}

MusicalComposition* find(char* a,MusicalComposition* head){
    int equal = 1; 
    int i;
    if(head==NULL){
        return head;
    }
    while(head!=NULL){
        equal = 1;
        for(i=0;i<80;i++){
            if(head->name[i]=='\0')
                break;
            if(head->name[i]!=a[i])
                equal=0;
        }
            if(equal==1)
            return head;
          
            head=head->next;
       
    }
    return NULL;
   
}

MusicalComposition*  swap_list(MusicalComposition* head, char* a ,char* b){

    MusicalComposition* lst1=find(a,head); //dfgdfd
    MusicalComposition* lst2=find(b,head);

    MusicalComposition* p1=lst2->next;
    MusicalComposition* p2=lst1->prev;

    if(p2==NULL){
        lst2->next=lst1;
        lst2->prev=NULL;
        lst1->prev=lst2;
        lst1->next=p1;
        p1->prev=lst1;
        return lst2;
    }

    if(p1==NULL){
        lst1->next=NULL;
        lst1->prev=lst2;
        lst2->next=lst1;
        lst2->prev=p2;
        p2->next=lst2;
        return head;
    }

    lst1->next=lst2->next;
    lst1->prev=lst2;
    lst2->next=lst1;
    lst2->prev=p2;
    p2->next=lst2;
    p1->prev=lst1;
    return head;
}



MusicalComposition* sort(MusicalComposition* head){
    int k,i; //fdgfdg
    k=count(head);
    for(i=0;i<k;i++){
    if(head->next==NULL){
        return;
    }
    if(head->year > head->next->year){
        head = swap_list(head,head->name,head->next->name);


    }
    sort(head->next);
    }
    return head;
}


MusicalComposition* removeEl(MusicalComposition* head, char* name_for_remove){//sdsdsdsd
    int i;  //gfdfgdfgfd
    int equal=1;
    if(head==NULL){
        return NULL;
    }

    for(i=0;i<80;i++){
        if(head->name[i]=='\0')
            break;
        if(head->name[i]!=name_for_remove[i]){
            equal=0;
        }
    }
    if(equal==1){
        if(head->next==NULL&&head->prev==NULL){
            return NULL;
        }
        if(head->prev==NULL){
            head=head_del(head);
            return head;
        }
        if(head->next==NULL){
            head=tail_del(head);
            return head;
        }
        
        head->prev->next=head->next;
        head->next->prev=head->prev;
        free(head);
        return;
    }
    if(head->next==NULL)
        return;
    removeEl(head->next,name_for_remove);
    return head;
}

int count(MusicalComposition* head){
    int i=0; //fdgfdgfdg
    MusicalComposition*cur=head;
    while(cur!=NULL){
        i++;
        cur=cur->next;
    }
    return i;
}
MusicalComposition* add_elem(MusicalComposition* head,MusicalComposition* list,char* a){
    MusicalComposition* list1=find(a,head);
     if(list1==NULL){
        printf("\n\nТакой музыкальной композиции не существует\n\n");
        return;
     }
    if(list1->next==NULL){
        head=push(head, list);
        return head;
    }
     MusicalComposition* p1=list1->next;
     
      
      list1->next=list;
      list->prev=list1;
      list->next=p1;
      p1->prev=list;
      return head;
    
}
void print_names(MusicalComposition* head){
    if(head==NULL){ ///fdgdfgfdgfd
        return;
    }
    printf("Песня: %s \nИсполнитель %s\nГод: %i\n",head->name,head->author,head->year);
    print_names(head->next);
}

MusicalComposition* clean_list(MusicalComposition* head){
    if(head==NULL)
      return ;
    MusicalComposition* p;
    MusicalComposition* p1;
    while(head!=NULL){
        p=head;
        head=head->next;
    }
       p1=p;
    while(p1!=NULL){
        
        if(p1->prev!=NULL)
           p1->prev->next=NULL;
           
        p1->prev=NULL;
        p1=p1->prev;
        
        free(p1);
    }
    
    return NULL;
    
}


int main(){
    
    int variable;
    int i=0,k=0;
    char name[80];
    char author[80];
    char name_for_remove[80];
    char name_add[80];
    int year;
    MusicalComposition* head=NULL;
     

    while(variable!=0){
    printf("Для выхода введите '0'\n");
    
    printf("Введите '1' для добавления элемента в список\nВведите '2', чтобы посмотреть список\nВведите '3', чтобы отсортировать список\n");
    printf("Введите '4' чтобы удалить элемент\nВведите '5' чтобы добавить элемент в начало списка\n");    
    printf("Введите '6' чтобы добавить элемент после какого-либо элемента\nВведите '7' чтобы посчитать количество элементов списка\n");
       
    scanf("%i",&variable);
    
     
     switch ( variable ) {
        case 1:
        
            
            printf("Введите название музыкальной композиции:");
            getchar();
            fgets(name, 80, stdin);
            printf("Введите автора музыкальной композиции:");
            fgets(author, 80, stdin);
            printf("Введите год публикации музыкальной композиции:");
            scanf("%d", &year);
            getchar();
            (*strstr(name,"\n"))=0;
            (*strstr(author,"\n"))=0;
            if(i==0)
            head = createMusicalCompositionList(head,name, author, year);
            else {
               MusicalComposition* element_for_push = createMusicalComposition(name, author, year);
               head=push(head,element_for_push);
                
            }
            i=1;
        break;
        
        case 2:
        printf("\n");
          print_names(head);
        printf("\n");
        break;
        
        case 3:
          head=sort(head);
          if(head!=NULL)
          printf("\n**********Список отсортирован***************\n");
          else
          printf("\n********** Заполните список :( ***************\n");
        break;
        
        case 4:
        if(head!=NULL){
        printf("Введите название музыкальной композиции, чтобы удалить её:");
        getchar();
        fgets(name_for_remove, 80, stdin);
        (*strstr(name_for_remove,"\n"))=0;
        head=removeEl(head, name_for_remove);
        }
        else 
         printf("\nСписок пуст - нечего удалять :) \n\n");
        break;
        case 5:
        
            
            printf("Введите название музыкальной композиции:");
            getchar();
            fgets(name, 80, stdin);
            printf("Введите автора музыкальной композиции:");
            fgets(author, 80, stdin);
            printf("Введите год публикации музыкальной композиции:");
            scanf("%d", &year);
            getchar();
            (*strstr(name,"\n"))=0;
            (*strstr(author,"\n"))=0;
            if(i==0)
            head = createMusicalCompositionList(head,name, author, year);
            else {
               MusicalComposition* element_for_push = createMusicalComposition(name, author, year);
               head=tail_add(head,element_for_push);
                
            }
            i=1;
        break;
        case 6:
            if(head!=NULL){
            printf("Введите название музыкальной композиции, после которой хотите добавить элемент:");
            getchar();
            fgets(name, 80, stdin);
            printf("Введите название музыкальной композиции, которую хотите добавить:");
            fgets(name_add, 80, stdin);
            printf("Введите автора музыкальной композиции, которую хотите добавить:");
            fgets(author, 80, stdin);
            printf("Введите год публикации музыкальной композиции, которую хотите добавить:");
            scanf("%d", &year);
            getchar();
            (*strstr(name,"\n"))=0;
            (*strstr(name_add,"\n"))=0;
            (*strstr(author,"\n"))=0;
            MusicalComposition* element_for_push = createMusicalComposition(name_add, author, year);
            
               
               head=add_elem(head,element_for_push,name);
               
               }
               else
                printf("Список пуст\n");
            
        break;
        case 7:
        
        printf("В списке: %d(-ов)\n\n",count(head));
        break;
        case 8:
        
        break;
}       
    }
    head=clean_list(head);
    free(head);

 
    return 0;

}










