#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ll T;
	cin>>T;
	while(T--){
			ll N;
			cin>>N;
			vector<ll> A(N, 0);
			vector<ll> M(N+1, 0);
			unordered_map<ll,vector<ll>> index;
			
			for(ll i=0; i<N; i++) cin>>A[i];
			for(ll i=1; i<N+1;i++) M[i]=M[i-1]^A[i-1];
		  ll cnt=0;
		  for(ll i=1; i<N+1; i++){
		  	 if(M[i]==0)
		  	 	 cnt += i-1;
		  	 index[M[i]].push_back(i);
			}
		  for(auto x : index){
		  	 if(x.second.size()>1){
		  	 		ll n = x.second.size(), ans=0;
		  	 		vector<ll> p = x.second;
		  	 		sort(p.begin(), p.end());
		  	 		for(ll i=n-1; i>=0; i--){
		  	 			ans += i*p[i] - (n-1-i)*p[i];
		  	 			//cout<<p[i]<<" ";
						}
						cnt += ans -(n*(n-1))/2;
				 }
	  	}
	  	cout<<cnt<<endl;				
	}
	return 0;
}

