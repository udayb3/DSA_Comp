## Implementation of Hash table using Chaining
### Using Structures
```cpp
struct Hash
{
  ll buc; list<ll> *tab;
  Hash(ll val)
  {
    buc= val;
    tab= new list<ll>[val];
  }
  void ins(ll key){
    ll t1= key%buc;
    tab[t1].push_back(key);
  }
  void del(ll key){
    ll t1= key%buc;
    tab[t1].remove(key);
  }
  bool sea(ll key){
    ll t1= key%buc;
    for(auto it1:tab[t1] ){
      if( it1==key ){return true;}
    }
    return false;
  }
};
```

## Partial Implementation of Double Hashing
```cpp
struct Ohash
{
  ll n; ll st[];

  Ohash(ll sz){
    bl= sz;
    st= new array<ll>[sz]
  }
  ll hash(ll val, ll it)
  {
    return (val%n + it*((n-1) - (val%(n-1))))%n;
  }
  bool ins(ll val)
  {
    ll i=0; ll key= hash(val, i);
    if(st[key]<0 )
     { st[key]= val; return true;}
    for(i=1;i<n;i++){
      key= hash(val, i);
      if(st[key]==-1){
        st[i]=val; return true;
      }
    }
    return false;
  }
  bool rem(ll val)
  {
    ll i=0, key= hash(val, i);
    if(st[key]==val)
    {st[key]=-2; return true;}
    else if(st[key]==-1){
      return false;
    }
    for(i=1;i<n;i++){
      key= hash(val,i);
      if(st[key]==val)
        {st[key]=-2; return true;}
      else if(st[key]==-1){
        return false;
      }
    }
    return false;
  }
  bool sea(ll val)
  {
    
  }
};
```

## Finding if two elements have the given sum in the array
```cpp
bool ch(vl arr, ll k){
  usl st1;
  for(auto i:arr){
    if(st1.count(i)==1){
      if(st1.count(k-i)==1){
        return true;
      }
    }
    else{
      st1.insert(i);
    }
  }
  return false;
}
```

## Find the largest size array with equal number of 0's and 1's
```cpp
ll LongSub(vl arr, ll n)
{
  umll m1; ll res=-1, pre=0;
  for(ll i=0;i<n;i++){
    pre+= arr[i]==0?-1:1;
    if( pre==0 ){res= max(res, i+1); }
    if( m1.count(pre)==1 )
      res= max(res, i-m1[pre]);
    else
      m1[pre]= i;
  }
  return res;
}
```

## Finding longest common span with same sum in 2 arrays, Another approach is to subtract the second array from first element-wise.
```cpp
ll LongestSpan(vl a, vl b, ll n)
{
  umll m1; ll res=-1, pre1=0, pre2=0;
  for(ll i=0;i<n;i++){
    pre1+= a[i]; pre2+= b[i];
    if(pre2 == pre1)
      res= max(res, i+1);
    if(  m1.count(pre2-pre1))
      res= max(res, i- m1[pre2-pre1]);
    else
      m1[pre2-pre1]= i;
  }
  return res;
}
```
## Longest subsequence with Continuous elements
```cpp
int LongestSub(vl arr, ll n)
{
  usl st1(arr.begin(), arr.end()); ll coun=0, ans=0;
  for(int i=0;i<n;i++){
    if( st1.count(arr[i]-1)==0 )
    {
      coun= 1;
      while(st1.count(arr[i]+coun)==1){
        coun++;
      }
      ans= max(coun, ans);
    }
  }
  return ans;
}
```