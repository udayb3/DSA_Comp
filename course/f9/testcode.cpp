#include<bits/stdc++.h>
using namespace std;

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
typedef map<char,long long> mci;
typedef unordered_set<long long> usl;
typedef unordered_set<char> usc;
typedef unordered_map<long long,long long> umll;
typedef unordered_map<char,long long> umcl;

#define NL "\n"
#define SZ(v) ((int)v.size())
#define PB push_back
#define MP make_pair
#define fir first
#define sec second
#define PI 3.1415926535897
#define ALL(x) (x).begin(), (x).end()
#define VSR(a,i,j) (a).begin()+i, (a).begin()+j

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

template<typename T>
T solve()
{
  vl a{0, 1, 0 , 0, 0, 0}, b{1,0,1,0,0,1};
  cout << LongestSpan(a, b, 8) << "\n";
}

int main()
{
  // it avoids the synchronisation with the standard C streams
  ios_base::sync_with_stdio(false);
  // it guarantees the flushing of the cout method before taking the input again using cin. can be used for interactive problems
  cin.tie(NULL);

  int tst=1;  // cin >> tst;
  while(tst--)
  {
    solve<void>();
  }
  return 0;
}