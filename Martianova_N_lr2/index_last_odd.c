int index_last_odd(int a[],int i){
int k=i;
for(k=i;k>=1;--k){
	if(a[k]%2)
		break;
	}
return (k-1);
}
