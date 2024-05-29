## Rotating the array by 90 degree
```cpp
void Rmatrix(vvl &vec, int n)
{
  int l=0;
  while(l<n/2)
  {
    for(int i=l;i<n-1-l;i++){
      ll t1= vec[l][i];
      vec[l][i]= vec[i][n-1-l];
      vec[i][n-l-1]= vec[n-1-l][n-1-i];
      vec[n-1-l][n-1-i]= vec[n-i-1][l];
      vec[n-1-i][l]= t1;
    }
    l++;
  }
}
```

## Printing the Spiral form of a Square Matrix
```cpp
void Smatrix(vvl &arr, int n)
{
  int tp=0, lft=0, btm=n-1, rht=n-1;
  while(lft<=rht && tp<=btm)
  {
    for(int i=lft;i<=rht;i++)
      cout << arr[tp][i] << " ";
    tp++;
    for(int i=tp;i<=btm;i++)
      cout << arr[i][rht] <<" ";
    rht--;
    if(tp<=btm){
      for(int i=rht;i>=lft;i--)
        cout << arr[btm][i] << " ";
      btm--;
    }
    if(lft<=rht){
      for(int i=btm;i>=tp;i--)
        cout << arr[i][lft] << " ";
      lft++;
    }
  }
}
```