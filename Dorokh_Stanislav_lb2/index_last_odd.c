int index_last_odd(int arr[], int k){
int last=0;
int i=0;

 for (i=0;i<k;i++){
   if (arr[i] %2 !=0)
    last = i;
 }

return last;
}
