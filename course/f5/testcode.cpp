#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<int,int>> vpii;
typedef vector<pair<long long ,long long>> vpll;
typedef vector<pair<char,int>> vpci;
typedef vector<string> vstr;
typedef set<int> si;
typedef set<string> sstr;
typedef map<int,int> mii;
typedef map<char,int> mci;

#define SZ(v) ((int)v.size())
#define PB push_back
#define MP make_pair
#define fir first
#define sec second
#define PI 3.1415926535897
#define ALL(x) (x).begin(), (x).end()

template<typename T>
T solve()
{
  ll n; cin >> n; vl arr(n,0);
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  cout << maxCirs(arr,n)<<endl;
}

int main()
{
  int tst=1; //cin >> tst;
  while(tst--)
  {
    solve<void>();
  }
  return 0;
}
