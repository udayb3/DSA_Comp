## Rabin-Karp Algorithm
```cpp
const long long mod= 10e9+7;
void RabinKarp(string &txt, string &pat)
{
  ll n=txt.size(), m=pat.size();
  ll hval= 0, d=7;
  for(int i=0;i<m;i++){
    hval= (hval*d+ (pat[i]))%mod;
  }
  ll chash=0;
  int dn= 1;
  for(int i=1;i<m;i++){
    dn= (dn*d)%mod;
  }
  for(int i=0;i<m;i++){
    chash= (chash*d+ (txt[i]))%mod;
  }
  int j=m;
  for(int i=0; i<n-m+1;i++){
    if( hval==chash ){
      bool ch=true;
      for(int k=0;k<m;k++){
        if(pat[k]!=txt[i+k]){
          ch= false; break; 
        }
      }
      if(ch){cout << i << " ";}
    }
    if(i<n-m){
      chash= ( d*(chash-dn*txt[i]) + txt[i+m] )%mod;
      if(chash<0){chash+=mod;}
    }
  }
}
```
## Longest Proper prefix suffix array
```cpp
```
## KMP algorithm
```cpp
```
## Count of Lexicographically smaller string
```cpp
```