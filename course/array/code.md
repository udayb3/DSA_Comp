### Finding maximum sum in a array(negative elements too)
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
### Finding the maximum sum in a circular array
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
### finding majority element
```cpp
int majorityElement( vt<int> arr, int n ) {
  int n = arr.size(), candidate = -1, c = 0;
  for (int num : arr) {
    if (c == 0) {
      candidate = num;
      c = 1;
    } else if (num == candidate) {
      c++;
    } else {
      c--;
    }
  }
  return candidate
}
```
### Concept of Difference Array
- USECASE: Given a sequence of range update queries and final result is asked over an array.
- Idea is to make a dif array and for each range, perform following:
```cpp
for(i,l,r,v)
	diff[l] += v;
	dif[r+1] -= v;
```
- After doing this on all ranges, make prefix sum of dif and add each element to its corresponding to original array
```cpp
vt<int> update_ranges(vt<int> ar, vt<vt<int>> qu) {
	int n= ar.size(), m= qu.size(), i=0;
	vt<int> dif(n,0);
	forl(i,0,m-1){
		int l= qu[i][0], r = qu[i][1], v = qu[i][2];
		dif[l] += v; dif[r+1] -= v;
	}
	forl(i,0,n){
		ar[i] += dif[i];
	}
	return ar;
}
```
