## Array implementation of Deque
```cpp
```

## Maximum in all sub-arrays of size k
```cpp
void maxAll(vl arr, int n, int k)
{
  deque <int> usg;
  for(int i=0;i<n;i++){
    while( !usg.empty() && arr[usg.back()]<arr[i] ){
      usg.pop_back();
    }
    usg.push_back(i);
    if(usg.front()<=i-k){
      usg.pop_front();
    }
    if(i>=k-1){
      cout << arr[usg.front()] << " ";
    }
  }
}
```

## Finding the index which can complete the first circular tour[using deque]
```cpp
int FirstCir(vl pt, vl dt, int n)
{
  deque<ll> usg; ll cur=0; int i=0; int c1=0;
  // iterating 2 times the size of the array to check for the last element also
  while(i<2*n){
    cur+= pt[(i%n)]-dt[i%n];
    
    // Checking if proceeding on to the next factory will be possible/not
    if(cur<0){while(!usg.empty()){
      usg.pop_front();
      cur=0;
    }}
    else{
    usg.push_back( i%n );
    }

    // checking if all the factories are covered along with condition to counter segmentation fault
    if(!usg.empty() && usg.front()==usg.back() && usg.size()!=1){
      return usg.front()+1;
    }
    i++;
  }
  return -1;
}
```