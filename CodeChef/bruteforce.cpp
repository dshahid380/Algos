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
  freopen("input.in","r",stdin);
  //freopen("output.in","w",stdout);
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL); 
  int T; 
  cin>>T; 
  while(T--) {
  	int K,N,rem=0; 
  	cin>>N>>K;
  	int A[N],A2[N],A1[N]; 
  	For(i,0,N) {
  		 cin>>A[i];
  		 A2[i] = A[i];
  		 A1[i] = A[i];
		} 
  	
  	
  	//Bruteforce Approach
  	For(i,0,K) {
  		 A[i%N] = (A[i%N]^A[N-1-(i%N)]);
		}
		
		//My Logic
		 
		if(K!=N)
  	  rem = K%N;
  	int p = K/N;
  	if(K<=N) {
  		 for(int i=0; i<N; ++i)
  		   A2[i%N] = A2[i%N]^A2[N-1-i%N];
		}
		else {
			if(p%2==0) { 
				 for(int i=0; i<N; ++i) 
				   A2[i] = A2[i]^A2[N-1-i];
			}
			for(int i=0; i<rem; ++i)
			    A2[i] = A2[i]^A2[N-1-i];
		}
		int f=0;
		for(int i=0; i<N; ++i)
		  if(A[i]!=A2[i]) {
		  	f=1;
		  	break;
			}
		if(f==0) 
		  cout<<endl<<"OK"<<endl;
		else{
			 cout<<"N = "<<N<<", K = "<<K<<endl;
			 cout<<" === Actual array ===="<<endl;
			 for(int i=0; i<N; ++i)
			    cout<<A1[i]<<" ";
			 cout<<endl;
			 cout<<"========= Bruteforce ========== "<<endl;
			 for(int i=0; i<N; ++i)
			    cout<<A[i]<<" ";
			  cout<<endl;
			  cout<<"=========My Logic =========="<<endl;
			  for(int i=0; i<N; ++i)
			    cout<<A2[i]<<" ";
			  cout<<endl;
		} 
			   
	}
  return 0;
}

