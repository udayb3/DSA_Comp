#include<bits/stdc++.h>
using namespace std;

#define unset unordered_set
#define unmap unordered_map
#define pqu priority_queue
#define str string
#define grtr greater
#define vt vector
#define pb push_back
#define fir first
#define sec second
#define PI 3.1415926535897
#define iceil(a,b) (a-1)/b + 1;
#define ALL(x) (x).begin(), (x).end()
#define forl(i,a,b) for(i=a;i<b;i++)
#define rfor(i,a,b) for(i=a-1;i>=b;i--)
#define compgrpr [](const auto& a, const auto& b) { return a.fir > b.fir; } 

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;

int i=0,j=0,k=0;

int cPairs(vt<int> &arr,int l, int r, int md){
 // time complexity: O(n) if r-l==n

  int c=0,rt = md+1;
  i=l;
  forl(i,l,md+1) {
  while(rt<=r && arr[i]>2*arr[rt]) rt++;
    c += rt - (md+1);
  }
  return c;
}
void merge(vt<int> &arr, int l, int r, int md){
  vt<int> t1;
  int lt=l, rt=md+1;
  while(lt<=md && rt<=r) {
    if(arr[lt]<=arr[rt]){
      t1.pb(arr[lt]); lt++;
    } else {
      t1.pb(arr[rt]); rt++;
    }
  }
        
  while(lt<=md) t1.pb(arr[lt]), lt++;
  while(rt<=r) t1.pb(arr[rt]), rt++;    
  i=l;
  forl(i,l,r+1) arr[i] = t1[i-l];
}

int mergeSort(vt<int> &arr,int l,int r){
  int c=0, md = (l + r)/2;
        
  // Base case when the left element becomes equal to the right element
 if(l>=r) return c;
        
  // Dividing the problem into left and right parts
  c += mergeSort(arr,l,md); c += mergeSort(arr,md+1,r);
        
  // counting the # pairs which satisfy the condition given for ith index being 
  // from the left part and jth index being from the right part
  // Note that the above part provides me left and right subarray which are sorted 
  // internally. this is also the reason cPairs algorithm can be used
  c += cPairs(arr,l,r,md);
        
  // finally merging the array back
  merge(arr,l,r,md);
  return c;
}

int main() {
  
  int n; cin >> n;
  vt<int> arr(n,0);
  forl(i,0,n) cin >> arr[i];

  return mergeSort(arr,0,arr.size()-1);
}
