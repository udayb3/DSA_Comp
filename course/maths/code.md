### Counting the number of digits
```cpp
floor(log10(n)+1);
```
### Check Prime
- **Time comp: O($\sqrt{n}$)**
- 
```cpp
bool isPrime(long long n) {
  if(n==1){ return false; }
  if(n==2 || n==3) { return true;}
  if(n%2==0 || n%3==0){  return false;}
  for(int i=5;i*i<n+1;i=i+6) {
    if(n%i==0 || n%(i+2)==0) return false;
    }
	return true;
}
```
### Finding prime factors
```cpp
void pFac(ll n, vll &pf)
{
	ll i,j;
	forl(i,2,n){
		if(!pf[i].size()) continue;
		for(j=2;j<=n;j+=i) pf[j].pb(i);
	}
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
- This version uses the isPrime function [[maths/code#Check Prime]]
- **Time Comp: O($n\sqrt{n}$)**
```cpp
void Sieve(ll n, vll &prm ) {
  vbl vb(n+1,true);
  for(int i=2;i<=n;i++)
  {
    if(isPrime(i))
    {
      prm.push_back(i);
      for(ll j=i*i;j<=n;j++)
        vb[j]= false;
    }
  }
}
```
#### Optimized version(original sieve)
- Time comp: O($nlog(log n)$)
```cpp
vector<ll> Sieve(ll n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (ll p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (ll j = p * p; j <= n; j += p)
                prime[j] = false;
        }
    }

    vector<ll> primes;
    for (ll i = 2; i <= n; i++)
        if (prime[i]) primes.push_back(i);

    return primes;
}
```
#### More Optimized Version: Linear Sieve
- **Time comp: O(n)**
- **Space comp: O(n)**
```cpp
void MOSieve(int n, vt<int> &prm) {
	vt<int> lp(n+1);
	int i;
	forl(i,2,n){
		if(lp[i]==0) lp[i] = i, prm.pb(i);
		for(int j=0;i*prm[j]<=n;j++){
			lp[i*prm[j]] = prm[j];
			if(prm[j] == lp[i]) break;
		}
	}
}
```

### Modular Factorials(5,10) for independent value of n,k
- Uses [Lucas theorem](https://en.wikipedia.org/wiki/Lucas's_theorem) to find out modular factorials
- **Time Comp: O(log5 n)**
- **Space Comp: O(1)**
```cpp
auto binomMod5 = [](int n, int r) -> int {
	int b4t[5][5] = {{1,0,0,0,0},{1,1,0,0,0},{1,2,1,0,0},{1,3,3,1,0},{1,4,1,4,1}};
	int res = 1;
	while (n || r) {
	int nd = n % 5, rd = r % 5;
	if (rd > nd) return 0;
	
	res = (res * b4t[nd][rd]) % 5;
	n /= 5; r /= 5;
	}
	return res;
};

auto binomMod10 = [&](int n, int k) -> int {
	int r2 = ((n & ~k) == 0) ? 1 : 0;
	int r5 = binomMod5(n, k);
	return (5 * r2 + 6 * r5) % 10;
};
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

```cpp
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
### Divisibility Rules(Included only some, rest can be referred from [GFG](https://www.geeksforgeeks.org/maths/divisibility-rules/))

| Divisibility by | Rule |
| --- | --- |
| 7   | `( num[:-1] - 2 * num[-1] ) % 7 == 0` |
| 13  | modularly iterate over each digit of the number i.e. `ans = (ans + num[i])%10` and at last `ans` should be 0 |
| 17  | `(num[:-1] - 5*num[-1])%17==0` |
| 19  | `(num[:-1] + 2*num[-1])%19==0` |

### References
- [GeeksforGeeks](https://www.geeksforgeeks.org)
- [Optimized Sieve](https://cp-algorithms.com/algebra/prime-sieve-linear.html)
- [Binomial Coefficients](https://cp-algorithms.com/combinatorics/binomial-coefficients.html#pascals-triangle)