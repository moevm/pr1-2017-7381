#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char c;
    char *text = calloc(200, sizeof(char));
    int text_size = 0;
    while ((c = getchar()) != '!') {
         if (c=='\n' || c=='\t')
             continue;
         if (text_size%200==0 && text_size>0)
             text = realloc(text, (text_size+200)*sizeof(char));
         text[text_size] = c;
         text_size++;
    }
    if (text_size%200==0)
             text = realloc(text, (text_size+200)*sizeof(char));
    text[text_size]='!';
    text_size++;
    
    // � text �������� ������������ ����� ��� ��������� � ��������� �����
    
    
    int i, j, proverka, n=0, m=0, start=0, end;
    
    while (1){
        for (j=start;;j++){
            if (text[j]=='.' || text[j]==';' || text[j]=='?' || text[j]=='!'){
                end = j;
                n++;
                break;
            }
        } // ����� ������� �����������
        
        for (j=start+1, proverka = 1; j<=end; j++){
            if ( isdigit(text[j]) && !isspace(text[j-1]) && !isspace(text[j+1]) && !isdigit(text[j-1]) && text[j+1]!='.' && text[j+1]!=';' && text[j+1]!='!' && text[j+1]!='?' ){
                while (isdigit(text[j]))
                    j++;
                if (!isspace(text[j]) && text[j]!='.' && text[j]!=';' && text[j]!='?' && text[j]!='!'){
                    proverka = 0;
                    break;
                }
            }
        } // ��������, ���� �� ����� � ������ ����� �����������
        
        if (proverka){
            for (j=start; j<=end; j++)
                printf("%c", text[j]);
            printf("\n");
            m++;
        } // ���� ���� ���, ����� ��� ����������� � ������� ������
        
        if (text[end]=='!')
            break; // ���� ��� ���� ��������� �����������, �������� ����
        
        start=end+1;
        while (1)
            if (isspace(text[start]))
                start++;
            else
                break; // ������� � ���������� �����������
    }
    
    n--;
    m--;
    printf("���������� ����������� �� %d � ���������� ����������� ����� %d",n,m);
    free (text);
    return 0;
}