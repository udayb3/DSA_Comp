### Counting the number of digits
```cpp
floor(log10(n)+1);
```
### Checking if a number is prime or not
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
### Finding prime factors
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
### Finding all the divisors of a number
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
### Sieve of Eratosthenes
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
```
### Precomputing modular factorials, modular multiplicative inverse and factorial inverse

#### modular multiplicative inverse of a number
- For a number a and a modulus m, the modular multiplicative inverse of a (mod m) is a number b such that:
    a × b ≡ 1 % m

- In other words, b is the number that, when multiplied by a and taken modulo m, gives 1.

- For example, if a = 3 and m = 11, then the modular multiplicative inverse b = 4, because:
3 × 4 = 12 ≡ 1 %11
- The modular inverse can be computed in several ways:
  - Using the Extended Euclidean Algorithm (most general approach)
  - Using Fermat's Little Theorem (when m is prime): a^(m-2) ≡ a^(-1) % mod
  - Using the recursive formula shown

#### A factorial inverse refers to the modular multiplicative inverse of a factorial number
-Specifically, if we denote the factorial inverse of n! as (n!)^(-1), then:
  (n!) × (n!)^(-1) ≡ 1 (mod mod)

- Factorial inverses are particularly useful for calculating combinations and permutations efficiently in modular arithmetic. For example, the binomial coefficient "n choose k" can be calculated as:
  C(n,k) = n! / (k! × (n-k)!)
- In modular arithmetic, since we cannot divide, we multiply by the modular multiplicative inverse instead:
  C(n,k) ≡ n! × (k!)^(-1) × ((n-k)!)^(-1) % mod
- By precomputing both factorials and factorial inverses as in your code, these calculations become very efficient - just three lookups and two multiplications:
C(n,k) ≡ fact[n] × invFact[k] × invFact[n-k] %  mod

```
void precomp( int n ) {
  int i;
  fact.assign( n+1, 1 );
  forl( i,1,n+1 ) fact[i]=  fact[i-1] * i  % mod;

  inv.assign( n+1, 1);
  forl( i,2,n+1) inv[i]= mod - (mod/i) * inv[mod%i] % mod;
        
  invfact.assign( n+1, 1);
  forl(i,1,n+1) invfact[i]= invfact[i-1] * inv[i] % mod; 
}
```
#### Divisibility Rules(Included only some, rest can be referred from [GFG](https://www.geeksforgeeks.org/maths/divisibility-rules/))

| Divisibility by | Rule |
| --- | --- |
| 7   | `( num[:-1] - 2 * num[-1] ) % 7 == 0` |
| 13  | modularly iterate over each digit of the number i.e. `ans = (ans + num[i])%10` and at last `ans` should be 0 |
| 17  | `(num[:-1] - 5*num[-1])%17==0` |
| 19  | `(num[:-1] + 2*num[-1])%19==0` |

### Refrences
- [GeeksforGeeks](https://www.geeksforgeeks.org)