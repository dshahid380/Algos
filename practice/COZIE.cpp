#include<bits/stdc++.h>
#define ll long long 
using namespace std;

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

int main() {
	ll N, Q;
	cin>>N>>Q;
	vector<int> A;
	ll x;
	for(ll i=0; i<N; i++){
		cin>>x;
		A.push_back(x);
	}
	for(ll i=0; i<N; i++){
		A[i] = phi(A[i]);
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
