#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<int> 
#define vvi vector<vector<int>>
#define pll pair<ll, ll>
#define vl vector<ll> 
#define vvl vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define umap unordered_map
#define uset unordered_set
#define all(c) c.begin(), c.end()
#define maxarr(A) *max_element(A, A+n) 
#define maxvec(v) *max_element(all(v)) 
#define present(map,elem) map.find(elem)!=map.end()
#define lb(v,elem) (lower_bound(all(v),elem) - v.begin())
#define ub(v,elem) (upper_bound(all(v),elem) - v.begin())
#define pb push_back 
#define mp make_pair
#define For(i,a,b) for(int i=a; i<b; ++i) 
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define mod 1000000007 

int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  int T;
  cin>>T;
  while(T--) {
  	ll K,N,rem=0;
  	cin>>N>>K;
  	ll A[N];
  	rep(i,0,N) cin>>A[i];
  	if(N%2==0) {
  		 rep(i,0,(K%(3*N)))
  		    A[i%N] = A[i%N]^A[N-1-i%N];
		}
		else {
			 if(K<3*N) {
			 	 rep(i,0,K) 
			 	    A[i%N] = A[i%N]^A[N-1-i%N];
			 }
			 else{
			 	 ll rem = K%(3*N);
			 	 rep(i,0,3*N+rem) 
			 	 		A[i%N] = A[i%N]^A[N-1-i%N];
			 }
		}
		rep(i,0,N) 
		  cout<<A[i]<<" ";
		cout<<endl;
	}
  return 0;
}

