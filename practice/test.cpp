#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll MAX=1000006;
ll A[1000006];
vector<int> primes;

void prime_generator(){
	vector<char> is_prime(MAX,true);
	is_prime[0] = is_prime[1] = false;
	for(ll i = 2; i*i<=MAX; i++){
		if(is_prime[i]){
			for(ll j=i*i; j<=MAX; j+=i)
			    is_prime[j]=false;
		}
	}
	for(ll i=0; i<MAX; i++){
		if(is_prime[i])
		   primes.push_back(i);
	}
}
 
 
ll divisors(ll n){
  ll ans=1;
	for(int i=0; i<primes.size(); i++){
		if(primes[i]*primes[i] >n)
			break;
		ll temp=0;
		while(n % primes[i] == 0){
			temp++;
			n = n/primes[i];
		}
		ans = ans * (temp+1);
	}
	if(n > 1)
	  ans = ans * 2;
	return ans;
	
}
 
void preprocess(){
	prime_generator();
}
 
int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);	
  preprocess();
  #cout<<primes.size()<<endl;
  ll T;
  scanf("%lld", &T);
  while(T--){
  	ll a, b;
  	scanf("%lld %lld", &a, &b);
  	ll ans, g;
  	g = __gcd(a, b);
  	if(g==1)
  	  ans = 1;
  	else
  	  ans = divisors(g);
  	printf("%lld \n", ans);	
  }
  return 0;	
} 
