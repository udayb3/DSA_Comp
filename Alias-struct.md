## Macros and CF template
```cpp
#include<bits/stdc++.h>
using namespace std;

#define unset unordered_set
#define unmap unordered_map
#define pqu priority_queue
#define grtr greater
#define vt vector
#define pb push_back
#define fir first
#define sec second
#define cbit __builtin_popcount
#define PI 3.1415926535897
#define imax 1e9+7
#define lmax 1e18+7
#define icl(a,b) (a-1)/b + 1;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forl(i,a,b) for(i=a;i<=b;i++)
#define rfor(i,a,b) for(i=a;i>=b;i--)
#define fin(ar, n) {for(int ind1=0;ind1<=n;ind1++){cin >> ar[ind1];}}
#define fou(ar,n) {for(int ind1=0;ind1<=n-1;ind1++){cout << ar[ind1];}}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;

inline size_t key(int i,int j) {return (size_t) i << 32 | (unsigned int) j;}

vt<vt<int>> direc{{1,0},{0,1},{-1,0},{0,-1}};

template<typename T>
T solve() {	 
	
}
int main()
{
	// it avoids the synchronisation with the standard C streams
	ios_base::sync_with_stdio(false);
	// it guarantees the flushing of the cout method before taking the input again using cin.
	cin.tie(NULL);
	int tst=1;   //cin >> tst;
	while(tst--)
	{
		solve<void>();
	}
	return 0;
}
```

## Node for tree
```cpp
struct tnode
{
  ll dt;
  tnode *lt;
  tnode *rt;
  tnode(ll val){
    dt= val;
    lt= NULL; rt=NULL;
  }
};
```
## Using lambda operators in cpp
- In the expression below, `[&]` captures all the local variables from surrounding scope i.e. any outside variable can also be modified.
```cpp
auto usage= [&](int a, int b){
	//operation 
};
```