#include <stdio.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
int multi_between_negative(int N[],int h)
{
int B,i,m,P;

	B=index_first_negative(N,h);
		

    m=index_last_negative(N,h);
    P=N[B];



	for (i=0;i<=h;i++){
		if (i>B && i<m) 
	
        {
        	P=P*N[i];}
       }

return P;
}
