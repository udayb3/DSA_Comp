## Problems
<!-- AUTO-GENERATED-CONTENT:START (TOC:collapse=true&collapseText="Click to expand") -->
<details>
<summary>Index</summary>

- [0-1-Knapsack](#problem1)
- [Unbounded Knapsack](#problem2)
- [Longest Common Sequence](#problem3)
- [Matrix Chain Multiplication](#problem4)
- [Boolean Paranthesization](#problem5)
- [Scrambled Strings](#problem6)
- [Egg Dropping](#problem7)

</details>
<!-- AUTO-GENERATED-CONTENT:END -->

## Problem1
### 0-1 Knapsack problem
#### Recursive + memoization
```cpp
int recur_knap01(vpii &arr, int n, int w, vector<vi> &dp )
{
  // Base condition
  if(n==0 || w==0)
    return 0;

  // memoization
  if( dp[n][w]!=-1)
    return dp[n][w];

  // recursive relation
  int pr= arr[n-1].fir, we= arr[n-1].sec;
  if( we<=w ){
    dp[n][w]= max( pr + recur_knap01(arr, n-1, w-we, dp ),  recur_knap01(arr, n-1, w, dp));
  }
  else{
    dp[n][w]= recur_knap01(arr, n-1, w, dp);
  }
  return dp[n][w];
}
```
#### Bottom-top approach
```cpp
int iter_01knap(vpii &arr, int n, int w)
{
  vector<vi> dp( n+1, vi(w+1, -1));
  for(int i=0;i<n+1;i++){
    for(int j=0;j<w+1;j++){
      
      // Initialisation
      if( i==0 || j==0 )
        dp[i][j]=0;
      
      else{
        // memoization
        if(arr[i-1].sec<=j){
          dp[i][j]= max( arr[i-1].fir + dp[i-1][j- arr[i-1].sec], dp[i-1][j] );
        }
        else
          dp[i][j]= dp[i-1][j];
      }
    }
  }
  return dp[n][w];
}
```
## Problem2
### Unbounded Knapsack
#### Recursive + Memoization
```cpp
int recur_knapUnbound( vector< pii > &arr, int n, int tot, vector< vi> &dp)
{
  // Base Condition
  if( n==0 || tot==0 )
    return 0;
  
  // Checking for memoization
  if( dp[n][tot]!= -1)
    return dp[n][tot]; 

  // In the pair arr[i], first part is weight and second part is value
  if( arr[n-1].fir <= tot ){
    dp[n][tot]= max( arr[n-1].sec + recur_knapUnbound( arr, n , tot - arr[n-1].fir, dp ), recur_knapUnbound( arr, n-1, tot, dp ) );
  }
  else
    dp[n][tot]= recur_knapUnbound( arr, n-1, tot, dp );
  
  return dp[n][tot];
}
```
#### Bottom-top approach
```cpp
int iter_knapUnbound( vector< pii> &arr, int n, int tot )
{
  vector< vi > dp( n+1 , vi( tot +1, -1) );
  for(int i=0;i<n+1;i++){
    for(int j=0;j<tot+1;j++){
      
      if(i==0 || j==0 )
        dp[i][j]= 0;
      else if( arr[i-1].fir <= j )
        dp[i][j]= max( arr[i-1].sec + dp[i][j - arr[i-1].fir ], dp[i-1][j] );
      else
        dp[i][j]= dp[i-1][j];  
    
    }
  }
  return dp[n][tot];
}
```
## Problem3
### Longest Common Subsequence
#### Recursive Solution
```cpp
int recur_LCS( string a, string b, int n, int m, vector< vi> &dp)
{
  // Base Case
  if( n==0 || m==0 )
    return 0;

  // Memoization
  if( dp[n][m]!=-1 )
    return dp[n][m];

  // Recursive relation
  if( a[n-1] == b[m-1] )
    dp[n][m]= 1+recur_LCS(a,b, n-1,m-1, dp);
  else
    dp[n][m]= max( recur_LCS(a,b,n-1,m, dp) , recur_LCS(a,b, n, m-1, dp) );
  
  return dp[n][m];
}
```
#### Bottom-top approach
```cpp
int iter_LCS( string a, string b, int n, int m)
{
  vector< vi > dp(n+1 , vi(m+1, -1) );
  
  for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
      // Initialisation
      if( i==0 || j==0 )
        dp[i][j]= 0;
      else{
        // Recursive condition with memoization
        if( a[i-1] == b[j-1] )
          dp[i][j]= 1 + dp[i-1][j-1];
        else
          dp[i][j]= max( dp[i-1][j] , dp[i][j-1] );
      }
    }
  }
  return dp[n][m];
}
```
## Problem4
### Matrix-Chain Multiplication
#### Recursive Solution[optimized version]
```cpp
int recur_MCM(vi &arr, int i, int j, vector< vi > &dp )
{
  // Base condition
  if(i>=j)
    return 0;
  
  // Memoization
  if( dp[i][j] != -1 )
    return dp[i][j];

  // Checking for value of k which will produce best result
  int ans=INT_MAX, t1;
  for(int k=i;k<=j-1;k++){
    
    // optimized version: memoization yahan bhi use hai
    if(dp[i][k]!=-1)
      dp[i][k]= recur_MCM( arr, i, k, dp );
    if(dp[k+1][j]!=-1)
      dp[k+1][j]= recur_MCM( arr, k+1, j, dp);

    t1= dp[i][k]+dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
    ans= min(t1, ans);
  }
  return ans;
}
```
#### Bottom-top approach
```cpp
```
## Problem5
### Boolean Parathesization
#### Recursive Solution
```cpp
int recur_BoolParath(string p, int i, int j, bool B, vector<vector< pii> > &dp )
{
  // dp is 2D matrix of pairs where first and second are the number of ways we can get true and false resp. in the sub-string from ith to jth index 
  // Map bhi use kar sakte hai

  // Base condition
  if(i>j)
    return 0;
  if(i==j){
    if(B)
      return ((p[i]=='T')?1:0 );
    else
      return ((p[i]=='F')?1:0 );
  }

  // Memoization
  if( B && dp[i][j].fir!=-1)
    return dp[i][j].fir;
  else if( !B && dp[i][j].sec!=-1)
    return dp[i][j].sec;
  
  // recurrence relation
  int ans=0;
  for( int k=i+1;k<=j-1;k+= 2 ){
    
    int LT= recur_BoolParath(p,i,k-1,true, dp); int LF= recur_BoolParath(p,i,k-1,false, dp);
    int RT= recur_BoolParath(p,k+1,j,true, dp); int RF= recur_BoolParath(p,k+1,j, false, dp);

    if( p[k]=='|' ){
      if(B)
        ans+= LT*RT + LT*RF + LF*RT;
      else
        ans+= LF*RF;
    }
    else if(p[k]=='&'){
      if(B)
        ans+= LT*RT;
      else
        ans+= LT*RF + RT*LF + LF*RF;
    }
    else if(p[k]=='^'){
      if(B)
        ans+= LT*RF +LF*RT;
      else
        ans+= LF*RF + LT*RT;
    }
  }
  if(B)
    dp[i][j].fir= ans;
  else

  return ans;
}
    dp[i][j].sec= ans;
```
## Problem6
### Scrambled Strings
#### Recursive Solution
```cpp
```
## Problem7
### Egg dropping
#### Recursive solution
```cpp
int recur_eggDrop( int egg, int floor, vector<vi> &dp)
{
  // Base case
  if( floor==0 || floor==1 || egg==1)
    return floor;

  // Memoization
  if( dp[egg][floor]!= -1 )
    return dp[egg][floor];

  // Recrusive solution: logic hai ki hum find karte hai agar kth floor par egg break ho gaya/nahi hua toh worst case lena hai
  int ans= INT_MAX; int p1, p2;
  for(int k=1;k<=floor;k++){

    if( dp[egg-1][k-1]==-1 )
      dp[egg-1][k-1]= recur_eggDrop( egg-1, k-1, dp);
    if( dp[egg][floor-k]==-1)
      dp[egg][floor-k]= recur_eggDrop( egg, floor-k, dp);

    int t1= 1+ max( dp[egg-1][k-1] , dp[egg][floor-k]);
    ans= min(t1, ans);
  }
  dp[egg][floor]= ans;
  return ans;
}
```