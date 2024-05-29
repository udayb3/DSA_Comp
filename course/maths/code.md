- ### Counting the number of digits
```cpp
floor(log10(n)+1);
```
- ### Checking if a number is prime or not
```cpp
bool isPrime(long long n)
  {
  if(n==1){ return false; }
  if(n==2 || n==3) { return true;}
  if(n%2==0 || n%3==0){  return false;}
  for(int i=5;i<sqrt(n)+1;i=i+6)
  {
    if(n%i==0 || n%(i+2)==0)
      {return false;}
  }
    return true;
  }
```
- ### Finding prime factors
```cpp
void primeFactors(ll n, vll &pf)
{
  if(n<=1)
    return ;
  while(n%2==0 && (n!=0))
  {
    pf.push_back(2); n/=2;
  }
  while(n%3==0 && (n!=0))
  {
    pf.push_back(3); n/=3;
  }
  for(ll i=5;(i*i)<n;i+=6)
  {
    while(n%i==0 && n!=0){
      pf.push_back(i); n/=i;
    }
    while(n%(i+2)==0 && n!=0){
      pf.push_back(i+2); n/=(i+2);
    }
  }
  if(n>3)
    pf.push_back(n);
}
```
- ### Finding all the divisors of a number
```cpp
void divisor(ll n, vll &div)
{
  div.push_back(1);
  ll i=2;
  for(i=2;i*i<n;i++)
  {
    if(n%i==0)
      { div.push_back(i);}
  }
  while(i>0)
  {
    if( n%(n/i)==0)
    {  div.push_back(n/i); }
    i--;
  }
}
```
- ### Sieve of Eratosthenes
```cpp
void Sieve(ll n, vll &prm )
{
  vbl vb(n+1,true);
  for(int i=2;i<=n;i++)
  {
    if(isPrime(i))
    {
      prm.push_back(i);
      for(ll j=i*i;j<=n;j++)
        vb[j]== false;
    }
  }
}

  
