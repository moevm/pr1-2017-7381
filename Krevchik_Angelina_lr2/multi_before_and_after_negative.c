#include <stdio.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
int multi_before_and_after_negative(int N[],int h)
{
int B,m,i,P;

	B=index_first_negative(N,h);
		

    m=index_last_negative(N,h);

    P=N[m];



	for (i=0;i<=h;i++){
		if (i<B || i>m) 
	
        {
        	P=P*N[i];}
       }

return P;
}
