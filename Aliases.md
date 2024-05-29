## Shortening the declarations of the variables
```cpp
typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<long long ,long long>> vpll;
typedef vector<vector<long long>> vvl;
typedef vector<pair<char,int>> vpci;
typedef vector<string> vstr;
typedef set<int> si;
typedef set<string> sstr;
typedef map<int,int> mii;
typedef map<char,int> mci;
```

## Defining some macros to be used for writing faster code
```cpp
#define NL "\n"
#define SZ(v) ((int)v.size())
#define PB push_back
#define MP make_pair
#define fir first
#define sec second
#define PI 3.1415926535897
#define ALL(x) (x).begin(), (x).end()
#define VSR(a,i,j) (a).begin()+i, (a).begin()+j
```

## Code template
```cpp
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

  int tst;   cin >> tst;
  while(tst--)
  {
    solve<void>();
  }
  return 0;
}
```