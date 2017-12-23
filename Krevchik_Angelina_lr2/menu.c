#include <stdio.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "multi_between_negative.h"
#include "multi_before_and_after_negative.h"

int main(){
	int B,K,C,L,o,i;
	int N[20];

scanf("%d",&o);
i=0;

while ((getchar())!='\n')
		scanf("%d",&N[i++]);



	switch(o)
	{
		case 0: B=index_first_negative(N,i-1);
				printf ("%d\n",B);
			break;
		
		case 1: K=index_last_negative(N,i-1);
				printf("%d\n",K);
			break;

		
		case 2: C=multi_between_negative(N,i-1);
		        printf("%d\n",C);
			break;		


		case 3: L=multi_before_and_after_negative(N,i-1);
		        printf("%d\n",L);
			break;	
		default: printf("Данные некорректны");	
	}
}
