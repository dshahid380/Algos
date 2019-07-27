#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll MAX=1000006;
ll prime[100000];
vector<char> is_prime(MAX, true);

void preprocess(){
	for(ll i=3; i<1001; i+=2){
		if(is_prime[i]){
			for(ll j = i*i; j<=MAX; j+=i)
			    is_prime[j] = false;
		}		
	}
	ll j = 1;
	prime[0]=2;
	for(ll i=3; i<=MAX; i+=2)
	    if(is_prime[i])
	       prime[j++]=i;
}

ll divisorsOfTwo(ll a, ll b){
	ll g = __gcd(a, b);
	if(g==1)
	   return 1;
	ll res=1;
	for(ll i=0; i<=78500 && prime[i]<g && g; i++){
		ll cnt=0;
		while(g%prime[i]==0){
			cnt++;
			g /= prime[i];
		}
		res *= (cnt+1);
	}
	if(g>1)
	  res *= 2;
	return res;
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);	
  preprocess();
  //cout<<primes.size()<<endl;
  ll T;
  cin>>T;
  while(T--){
  	ll a, b;
  	cin>>a>>b;
  	ll res=1;
  	ll g = __gcd(a, b);
	if(g==1)
	    res=1;
	else {
	
	for(ll i=0; i<=78500 && prime[i]<g && g; i++){
		ll cnt=0;
		while(g%prime[i]==0){
			cnt++;
			g /= prime[i];
		}
		res *= (cnt+1);
	}
	if(g>1)
	  res *= 2;
    }  
  	//ll ans = divisorsOfTwo(a, b);
  	cout<<res<<endl; 		
  }
  return 0;	
}
