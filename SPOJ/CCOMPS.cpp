#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vll vector<ll>
#define vii vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll> 
#define mod 1000000007

const int MAX = (int)1e5+3;
vector<bool> used(MAX, false);
vector<vector<int>> adj(MAX);

void dfs(int s) {
	 used[s] = true;
	 for( auto u : adj[s]) {
	 	  if(!used[u])
	 	     dfs(u);
	 } 
} 

int main() {
	 int N, M;
	 cin>>N>>M;
	 for(int i=0; i<M; ++i) {
	 	  int a,b;
	 	  cin>>a>>b;
	 	  adj[a].push_back(b);
	 	  adj[b].push_back(a);
	 }
	 int comp=0;
	 for(int i=1; i<=N; ++i) {
	 	  if(!used[i]){
	 	  	 comp++;
			 dfs(i); 
			}
	 	     
	 }
	 cout<<comp<<endl;
	 return 0;
	 
}
