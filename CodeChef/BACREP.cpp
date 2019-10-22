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
#define debug(A,N) For(i,0,N) cout<<A[i]<<" "
#define flush(adj,N) For(i,0,N+1) adj[i].clear()
#define mod 1000000007 

const ll MAX = 500005;
vvl adj(MAX);
vvl up;
vector<bool> used(MAX,false);
ll A[MAX], l;
vi leafs, lev(MAX,0);

void findLeaf(ll s) {
	used[s] = true;
	for(auto u : adj[s]) {
		if(!used[u]) {
			dfs(u);
			if(adj[u].size()==1)
				leafs.pb(u);
		}
	}
}

void findLevel(ll v, ll p) {
   lev[v] = lev[p] + 1;
   for(int u : adj[v]) {
       if(u!=p) 
         findLevel(u,v);
   }
}

void dfs(ll v, ll p) {
  up[v][0] = p;
  rep(i,1,l+1) {
    up[v][i] = up[up[v][i-1]][i-1];
  }
  for(int u : adj[v]) {
    if(u!=p) 
      dfs(u,v);
  }
}

int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  ll N,Q;
  cin>>N>>Q;
  rep(i,0,N-1) {
  	 int u,v;
  	 cin>>u>>v;
  	 adj[u].pb(v);
  	 adj[v].pb(u);
  }
  rep(i,1,N+1) 
  	cin>>A[i];
    
  findLeaf(1);
  return 0;
}
