#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size_str 10
char** add_str( char** , int , char* );
int main()
{
/*
  ввод строки с клавиатуры
  переделать её в текст
  отформатировать текст  
*/
  char **num_str = 0 ; // pointer for first index 
  char *str;
  int i=0;
  int k=0;
  int rem = 0;
  int dd=0;
  int con=2;
  char** sort=0;
  //enter text
  str = (char*) malloc( sizeof(char*) * 1 );
  sort = (char**)malloc( sizeof(char**) * 1000 );
  num_str = (char**)malloc( sizeof(char**) * 1000 );
  while( ( str[i] = getchar() ) != EOF)
    {
      str = realloc( str ,  sizeof(char*) * (i+2) );
      if ( str[i] == '.' || str[i] == ';' || str[i] == '?' || str[i] == '!' )
        {
          ++i;
          str[i] = '\0';
          num_str = add_str( num_str , k , str+rem );
          rem = i+1;
          k++;
        }
            i++;
    }
  // конец ввода текста
  //удаление табуляции
          
    for ( int j=0 ; j < k; j++ )
        if ( num_str[j][0] == '\t' )
          for ( int i=0; i < strlen(num_str[j]); i++ )
            num_str[j][i] = num_str[j][i+1];

  //конец удаления таб
     
  // удаление пробелов вначале

     for ( int j=0 ; j < k; j++ )
       while ( num_str[j][0] == ' ')
         for ( int i=0; i < strlen( num_str[j]) ; i++ )
             num_str[j][i] = num_str[j][i+1];           

  //  конец удаления пробелов


  // удаление предложений с 7 путем копирования 
  for ( int j=0 ; j < k; j++ )
    for ( int q=0; q < strlen(num_str[j]) ; q++ )
      if ( num_str[j][q] == '7'  )
        num_str[j] = "xxx";


  for ( int b=0; b<k ; b++ )
     if  ( num_str[b] != "xxx")
{
         sort[dd] = num_str[b];
         dd++;
       }

  for ( int pp=0; pp<dd; pp++ )
    puts( sort[pp] );
  // конец удаления 7

  printf("Количество предложений до %d и количество предложений после %d" , k-1 , dd-1);

  free(sort);
  free(num_str);
  free(str);

  return 0;
}

char** add_str( char** str , int count , char *string )

  {
    if ( count == 0 )
      str = (char**)malloc( sizeof(char**) * ( count + 1 ) );
    else
      {
        char **copy = (char**)malloc(   sizeof(char*) * ( count + 1 ) );
        for ( int i = 0; i < count ; i++ )
          copy[i] = str[i];

        free(str);
        str = copy;
      }
    str[count] = (char*)malloc( sizeof(char*) * (strlen(string)+1) );
    strcpy( str[count] , string );
    return str;
  }
                                             
