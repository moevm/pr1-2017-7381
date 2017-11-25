int index_first_even(int a[],int i){
int n;
for(n=1;n<i;++n){
	if((a[n]%2)==0)
	break;
	
}
return (n-1);
}
