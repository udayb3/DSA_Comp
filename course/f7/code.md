## Implementation of Quick Sort
```cpp
int partition( vl &arr, int l, int r)
{
  int piv= arr[r]; int ind=l-1;
  for(int i=l;i<=r;i++)
  {
    if(arr[i]<piv){
      ind++;
      iter_swap(arr.begin()+i, arr.begin()+ind);
    }
  }
  iter_swap(arr.begin()+r, arr.begin()+ind+1);
  return ind+1;
}

void quick(vl &arr, int l, int r){
  if(l<r){
    int p=partition(arr, l, r);
    quick(arr, l, p-1);
    quick(arr, p+1, r);
  }
}
```

## Implementation of Merge Sort
```cpp
void merge(vl &arr, int l, int m, int r )
{
  int i,j,k,n1=m-l+1, n2=r-m;
  vl L(n1,0), R(n2,0);
  for(i=0;i<n1;i++){
    L[i]= arr[i+l];
    cout << L[i] << " ";
  }
  cout << endl;
  for(j=0;j<n2;j++){
    R[j]= arr[m+1+j];
    cout << R[j] << " ";
  }
  cout << endl;

  i=0; j=0; k=l;
  while( i<n1 && j<n2 ){
    if( L[i]<=R[j] ){
      arr[k]= L[i]; i++;
    }
    else{
      arr[k]= R[j]; j++; 
    }
    k++;
  }
  while( i<n1 ){
    arr[k]= L[i]; i++; k++;
  }
  while(j<n2){
    arr[k]= R[j]; j++; k++;
  }
}

void mergeSort(vl &arr, int l, int r)
{
  if(l<r){
    int m= l+ (r-l)/2;
    mergeSort(arr,l,m); mergeSort(arr, m+1, r); merge(arr, l, m, r);
  }
}
```