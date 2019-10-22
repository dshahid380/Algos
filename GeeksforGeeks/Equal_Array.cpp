#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	 int T;
	 cin>>T;
	 while(T--) {
	 	  ll N;
	 	  cin>>N;
	 	  ll A[N];
	 	  for(ll i=0; i<N; i++) cin>>A[i];
	 	  ll pre[N+1];
	 	  pre[0]=0;
	 	  for(ll i=1; i<=N; ++i) {
	 	  	 pre[i] = pre[i-1]+A[i-1];  
			}
			ll res = (ll) 1e11+7;
			for(ll i=1; i<N; ++i) {
				 ll diff = pre[N]-pre[i]-pre[i];
				 if(diff>=0)
				 		res = min(res, diff);
			}
			if(res==(ll)1e11+7)
			   cout<<-1<<endl;
			else
			   cout<<res<<endl;
	 }
	 return 0;
}
