## Checking if a string has balanced paranthesis
```cpp
bool parathen(string &p, int n)
{
  stack<char> st1;
  int i=0;
  map<char,char> mp1{{'{','}'}, {'[',']'},{'(',')'}};
  while(i<n){
    if(p[i]=='(' || p[i]=='[' || p[i]=='{'){
      st1.push(p[i]);
    }
    else if( st1.empty() ){
      return false;
      }
    else{
      if(p[i] == mp1[st1.top()]){
        st1.pop();
      }
      else{
        return false;
      }
    }
    i++;
  }
  if(st1.empty())
    return true;
  else
    return false;
}
```

## Finding the span in the array
```cpp
void span(vl &arr, int n)
{
  if(n==0){
    return;
  }
  stack<pll>st1;
  st1.push( MP(INT_MAX,-1 ));
  // cout << 1 << " ";
  for(int i=0;i<n;i++){
    while( !(st1.empty()) && arr[i]>(st1.top()).fir){
      st1.pop();
    }
    int val= (st1.top()).sec; 
    cout << i-val << " ";
    st1.push( MP(arr[i],i)); 
  }
}
```
## Find area of largest rectangle formed by array elements(considering them blocks)
```cpp
long long calrec(vl &arr, int n)
{
  stack<ll> st1; st1.push(0); ll ans=arr[0];
  for(int i=1;i<n;i++){
    
    while( !(st1.empty()) && arr[st1.top()] >= arr[i] ){
      int t1= st1.top(); st1.pop();
      ans= max( ans, (st1.empty()?i+1:(i-t1+1))*arr[i] );
    }
    st1.push(i);
  }
  while( !(st1.empty()) ){
    int t1= st1.top(); st1.pop();
    ans= max(ans, (st1.empty()?n:(n-t1))*arr[t1] );
    
  }
  return ans;
}
```

## Find longest Rectangle with all 1's
```cpp
long long int longestrec1(vvl &arr, int r, int c)
{
  ll ans=0;
  for(int i=1;i<r;i++){
    for(int j=0;j<c;j++){
      if(arr[i][j]!=0){
        arr[i][j]=1+arr[i-1][j];
      }
    }
  }
  vl tem1(c,0);
  for(int i=r-1;i>-1;i--){
    for(int j=0;j<c;j++){
      tem1[j]= arr[i][j];
    }
    ans= max(ans,calrec(tem1, c));
  }
  return ans;
}
```
## Finding previous smallest element for each elements
```cpp
vt<int> preSmall(vt<int> &arr){
  stack<int> st;
  vt<int> ans(arr.size(), -1);
  int i=0;
  forl(i,0,arr.size()){
      int el= arr[i];
      while(!st.empty() and arr[st.top()]>=el) st.pop();
      
      if(st.empty())ans[i]=-1;
      else ans[i]= st.top();
      
      st.push(i);
  }
  return ans;        
}
```
## Create a stack with the function getmin() with O(1) auxi. space[handles negatives]
```cpp

```