## Shortening the declarations of the variables
```cpp
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
#define forl(i,a,b) for(int i=a;i<b;i++)
#define rfor(i,a,b) for(int i=a-1;i>=b;i--)
#define compgrpr [](const auto& a, const auto& b) { return a.fir > b.fir; } 

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;

int i=0,j=0,k=0;

template<typename T>
T solve()
{	 
}
int main()
{
	// it avoids the synchronisation with the standard C streams
	ios_base::sync_with_stdio(false);
	// it guarantees the flushing of the cout method before taking the input again using cin.
	cin.tie(NULL);
	int tst=1;   cin >> tst;
	while(tst--)
	{
		solve<void>();
	}
	return 0;
}```

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