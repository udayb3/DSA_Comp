
```cpp
ll maxNorm(vl arr, ll n)
{
  ll maxe= arr[0], vmax=arr[0]; 
  for(ll i=1;i<n;i++){
    maxe= max(maxe+arr[i], arr[i]);
    vmax= max(vmax, maxe);
  }
  return vmax;
}
```

```cpp
ll maxCirs(vl arr, ll n )
{
  // Finding the maximum sum of a sub-array in a normal array
  ll norm= maxNorm(arr,n);
  // Finding the maximum sum of a sub-array only for the circular array by finding minimum sum for a sub-array in a normal array
  ll sm=0;
  for(int i=0;i<n;i++){
    sm+= arr[i]; arr[i]= 0-arr[i]; 
  }
  ll cir= sm+maxNorm(arr,n);
  return max(cir,norm);
}
```