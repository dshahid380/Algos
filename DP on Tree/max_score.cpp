#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
const int mod = 1e9 + 7;
const int N = 3e5;

vi g[N];
int a[N], dp[N];
void dfs(int u, int par) {
	dp[u] = a[u];
	int maxx = 0;
	for(int child: g[u]) {
		if(child == par) continue;
		dfs(child, u);
		maxx = max(maxx, dp[child]);
	}
	dp[u] += maxx;
	
}

int main() {
     ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 int i, j, k, n, u, v;
	 
	 cin>>n;
	 
	 for(i = 0; i < n-1; i++) {
	 	cin>>u>>v;
	 	g[u].push_back(v);
	 	g[v].push_back(u);
	 }
	 
	 for(i = 1; i < n+1; i++ ) cin>>a[i];
	 
	 dfs(1, 0);
	 cout<<dp[1]<<endl;
	 return 0;
}