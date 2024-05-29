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

ll Bin(vl arr, ll n, ll k)
{
  ll l=0,r=n-1;
  while(l<=r)
  {
    ll mid= l+ (r-l)/2;
    if(arr[mid]==k)
      return mid;
    else if(arr[mid]>k)
      r=mid-1;
    else
      l=mid+1;
  }
  return -1;
}

template<typename T>
T solve()
{

}

int main()
{
  int tst=1; // cin >> tst;
  while(tst--)
  {
    solve<void>();
  }
  return 0;
}