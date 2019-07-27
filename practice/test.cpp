#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll MAX=1000006;
ll A[1000006];
vector<int> primes;
 
using u64 = uint64_t;
using u128 = __uint128_t;
 
u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}
 
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;
 
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
 
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
 
void prime_generator(){
	for(ll i = 2; i< 1001; i++){
		if(MillerRabin(i))
		   primes.push_back(i);
	}
}
 
 
ll divisors(ll n){
    ll ans=1;
	for(ll d: primes){
		if(d*d > n)
		   break;
		ll temp = 0;
		while(n % d == 0){
			temp++;
			n /= d;
		}
		ans *= (temp+1);
	}
	
	if(n > 1)
	   ans *= 2;
	
	return ans;
	
}
 
void preprocess(){
	prime_generator();
	A[0]=0, A[1]=1;
	for(ll i=2; i<MAX; i++){
		A[i] = divisors(i);
	}
}
 
ll divisorsOfTwo(ll a, ll b){
	ll g = __gcd(a, b);
	return A[g];
}
 
 
int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);	
  preprocess();
  ll T;
  cin>>T;
  while(T--){
  	ll a, b;
  	cin>>a>>b;
  	ll ans = divisorsOfTwo(a, b);
  	cout<<ans<<endl; 		
  }
  return 0;	
} 