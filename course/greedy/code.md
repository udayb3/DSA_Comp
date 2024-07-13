## Problems
<!-- AUTO-GENERATED-CONTENT:START (TOC:collapse=true&collapseText="Click to expand") -->
<details>
<summary>Index</summary>

- [Job Scheduling](#problem1)
- [Fractional Knapsack](#problem2)

</details>
<!-- AUTO-GENERATED-CONTENT:END -->

## Problem1
### Job Scheduling problem
```cpp
bool cmp(pii a, pii b)
{
  return a.sec < b.sec;
}

int JobScheduling( vpii &arr, int n )
{
  sort(ALL(arr), cmp);
  int lst=arr[0].sec, ans=1;

  for(int i=1;i<n;i++){
    if( arr[i].fir > lst ){
      lst=arr[i].sec; ans++;
    }
  }
  return ans;
}
```
## Problem2
### Fractional Knapsack
```cpp
bool cmp(pii a, pii b)
{
  double t1= ((double)a.fir)/((double)a.sec );
  double t2= ((double)b.fir)/((double)b.sec);
  return t2<t1;
}

double fracKnapsack( vpii &arr, int n, int w)
{
  sort(ALL(arr), cmp);
  double ans=0;

  for(int i=0;i<n;i++){
    if(w==0)
      break;
    if( arr[i].sec <= w){
      w-= arr[i].sec; ans+= arr[i].fir;
    }
    else{
      ans+= ((double)w  * ((double)arr[i].fir)/((double)arr[i].sec));
    }
  }
  return ans;
}
```