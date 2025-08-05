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
## Main intution behind Counting inversions is merge sort 
```cpp
int lt= st, rt= md+1;
int c=0;
vt<int> t1;
while(lt<=md && rt<=en){
    if( arr[lt]<=arr[rt] ){
        t1.pb(arr[lt]);
        lt++;
    }
    else{
        c+= md-lt+1; t1.pb(arr[rt]);
        rt++;
    }
}
```
## Heap sort
```cpp
void swap(long long int *p,long long int *q){
	*p+=*q;	*q=*p-*q; *p-=*q;
}

void MaxHeapify(vtll vec,int q)
{
	int temp=q,sz=vec.size(),l=-1,r=-1,lar=q;
	if(q*2<=sz-1)
		l=q*2;
	if(q*2+1<=sz-1)
		r=q*2-1;
	
	if(l!=-1)
		lar=vec[temp]>vec[l]?temp:l;
	if(r!=-1)
		lar=vec[lar]>vec[r]?lar:r;
	
	if(lar!=q){
		swap(&vec[lar],&vec[q]);
		MaxHeapify(vec,lar);
	}
}
void BuildHeap(vtll vect, int n)
{
	int sz=((n-1)/2)+1;
	while(sz--)
	{
		MaxHeapify(vect,sz);
	}
}
void Hpsort(vtll arr)
{
	int k=1,siz=arr.size();
	BuildHeap(arr,siz);
	while(k<siz)
	{
		
	}
}
```