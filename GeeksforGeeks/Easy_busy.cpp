#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vll vector<ll>
#define vii vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll> 
#define mod 1000000007

void print(ll A[], ll N) {
	 for(ll i=1; i<=N; i++) 
	    cout<<A[i]<<" ";
	    cout<<endl;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N,Q;
	cin>>N>>Q;
	ll A[N],B[N];
	for(ll i=0; i<N; i++) cin>>A[i];
	for(ll i=0; i<N; i++) cin>>B[i];
	ll pref1[2*N+1], pref2[2*N+1];
	pref1[0]=pref2[0]=0;
	pref1[1]=A[0], pref2[1]=B[0];
	for(ll i=2; i<=N; i++) {
		 pref1[i] = pref1[i-2] + A[i-1];
		 pref2[i] = pref2[i-2] + B[i-1];
	}
	print(pref1, N);
	print(pref2, N);
	
	//cin>>Q;
	
	while(Q--) {
		 ll l,r, t;
		 cin>>t;
		 if(t==1) {
		 	 cin>>l>>r;
		 	 if((r-l)%2==0) 
		 	    cout<<pref1[r]-pref1[max(0LL, l-2)] + pref2[r-1]-pref2[max(0LL,l-1)]<<endl;
		 	 else 
		 	    cout<<pref1[r-1] - pref1[max(0LL, l-2)] + pref2[r] - pref2[max(0LL, l-1)]<<endl;
		 }
		 else {
		 	 cin>>l>>r;
		 	 if((r-l)%2==0) 
		 	    cout<<pref2[r]-pref2[max(0LL, l-2)] + pref1[r-1]-pref1[max(0LL,l-1)]<<endl;
		 	 else 
		 	    cout<<pref2[r-1] - pref2[max(0LL, l-2)] + pref1[r] - pref1[max(0LL, l-1)]<<endl;
		 }
		 
	}
	return 0;
}
