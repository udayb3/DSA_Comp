## Finding Square root by using binary search
```cpp
ll SQRT(ll n)
{
  ll l=1,r=n/2;
  while(l<=r)
  {
    ll mid=l+ (r-l)/2;
    if( mid*mid <=n && (mid+1)*(mid+1)>n )
      return mid;
    else if(mid*mid>n)
      r=mid-1;
    else
      l=mid+1;
  }
  return n/2;
}
```
