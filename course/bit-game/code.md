## Counting number of set bits
  - ### The below Code is an implementation of Brian-Cunningham algorithm.
  - ### The time complexity is O(s) where s is the number of set bits.
  - ### Idea: 
    - On applying bitwise & operator on numbers n and n-1, we turn that last set-bit off.
    - We apply this operation until the number becomes 0.
  ```cpp
  int CountSet(int n)
  {
    int c1=0;
    while(n>0)
    {
      n=n&(n-1);
      c1++;
    }
    return c1;
  }
  ```

## Given an array which has all elements occuring even times except 2 elements.
  - ### Time Complexity: O(n)
  - ### Idea: 
    - First we try to get the XOR of the 2 elements. 
    - Then we find the first differentiating bit from the right most side.
    - Then we divide elements in two sets based on this previous number obtained.
  ```cpp
  vll 2OddOccur(vll arr, int n)
  {
    ll xorr=arr[0];
    for(int i=1;i<n;i++)
      xorr = xorr ^ arr[i];

    ll a=-1,b=-1,sn=xorr &(~(xorr-1));
    for(int i=0;i<n;i++)
    {
      if(arr[i]&sn !=0)
        {a= (a==-1)?arr[i]:a^arr[i];}
      else
        b= (b==-1)?arr[i]:b^arr[i];
    }
    return {a,b};
  }
  ```
## Finding PowerSet of a String
  ```cpp
  void PowerSet(vector<string> ans, string s, int n)
  {
    ll num= pow(2,n);
    for(ll i=0;i<num;i++){
      ll t1= i; int c=0; string t2="";
      while(t1>0){
        if(t1%2==1){
          t2= t2+s[c];
        }
        t1 /=2; c++;
      }
      ans.PB(t2);
    }
  }
  ```