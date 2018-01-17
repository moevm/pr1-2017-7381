#pragma once

#define LEN 80
void sort(Film* head,int n)
{
  Film* half1;
   Film* half2;
  Film* tmp=head;
  int i=0;
  int j,c;
  for(i=0;i<n/2;i++)
  {
    tmp=tmp->next;
  }


    half1=tmp->back;//убыване
  half2=tmp;//возросане
  half2->back->next=NULL;
  half2->back=NULL;
   //возросане
  Film* a;
  Film* b;
  int year;
  char name[LEN];
  char director[LEN];
  int flag = 1;
  
  if(!half2)
  return;
  
  while(flag)
  {
    b=half2;
    a=half2->next;
    flag=0;
    
    while(a)
    {
      if((b->year)>(a->year))
      {
        strcpy(name, b->name);
        strcpy(b->name, a->name);
        strcpy(a->name, name);
        
        strcpy(director, b->director);
        strcpy(b->director, a->director);
        strcpy(a->director, b->director);
        
        year=b->year;
        b->year=a->year;
        a->year=year;
        
        flag=1;
      }
      b=b->next;
      a=a->next;
    }
  }


  
  
  
  //убыване
  flag=1;
  
while(flag)
  {
    b=half1;
    a=half1->back;
    flag=0;
    
    while(a)
    {
      if((b->year)>(a->year))
      {
        strcpy(name, b->name);
        strcpy(b->name, a->name);
        strcpy(a->name, name);
        
        strcpy(director, b->director);
        strcpy(b->director, a->director);
        strcpy(a->director, b->director);
        
        year=b->year;
        b->year=a->year;
        a->year=year;
        
        flag=1;
      }
      b=b->back;
      a=a->back;
    }
  }

  //соединение
  half1->next=half2;
  half2->back=half1;


}
