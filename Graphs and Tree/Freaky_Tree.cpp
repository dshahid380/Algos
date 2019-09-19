#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<ll>
#define mp make_pair
int ans;

void dfs(int s, int par,vector<vector<pair<int,int>>> adj, vector<bool>v, int x=0) {
	  int f=1;
	  v[s]=true;
	  for(auto u : adj[s]) {
	  	 if(!v[u.first]) {
	  	  if(u.first!=par) {
	  	  	 f=0;
	  	  	 dfs(u.first, s, adj,v, x^u.second);
				}
		  }
		}
		if(f==1 && x%2!=0)
		  ans++;
}

int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int T;
	scanf("%d",&T);
	while(T--) {
		 int N;
		 scanf("%d",&N);
		 vector<vector<pair<int,int>>> adj(N+1);
		 vector<bool> v(N+1,false);
		 for(int i=0; i<N-1; i++) {
		 	   int a, b, w;
		 	   scanf("%d %d %d", &a, &b, &w);
		 	   adj[a].push_back(mp(b,w));
			   adj[b].push_back(mp(a,w));   
		 }
		 ans = 0;
		 dfs(1,0,adj,v);
		 printf("%d\n",ans);
	}
	return 0;
}
