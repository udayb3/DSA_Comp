## Sort the k-sorted array[ ith element is between (i-1)th and (i+1)th element in the sorted array]
```cpp
void ksortarray(vi &arr, int n, int k)
{
  priority_queue<int, vi, greater<int> > pq;
  for(int i=0;i<k+1;i++){
    pq.push(arr[i]);
  }
  int ind=0;
  for(int j=k+1;j<n;j++){
    arr[ind]= pq.top(); pq.pop(); ind++;
    pq.push(arr[j]);
  }
  while(!pq.empty()){
    arr[ind++]= pq.top(); pq.pop();
  }
}
```
## Find k largest element in the array
```cpp
```
## Merge k sorted array
```cpp
```