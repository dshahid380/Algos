#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>

ll phi(ll n){
  ll res = n;
  for(ll i = 2; i*i<=n; i++) {
	if(n%i==0) {
	  while(n%i==0)
		n/=i;
	  res -= res/i;
	}
  }
  if(n>1)
	res -= res / n;
  return res;
}

int main(){
  int T;
  cin>>T;
  while(T--){
	ll n;
	cin>>n;
	cout<<phi(n)<<endl;	
  }
  return 0;
}
