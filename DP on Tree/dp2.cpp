#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
vector<int> adj[MAX];
int dp[MAX];
int diameter;

void dfs(int p, int ch){
	vector<int>childDp;
	for(int x : adj[ch]){
		if(x!=p){
			dfs(ch, x);
			childDp.push_back(dp[x]);
		}
	}
	dp[ch] = 1;
	sort(childDP.begin(), childDp.end());
	dp[ch] += childDp.back();
	int subtreeDiameter = 0;
	if((int)childDp.size()>1){
		subtreeDiameter = 2 + childDp[(int)childDp.size()-1] + childDp[(int)childDp.size()-2];
	}
	diameter = max(dp[ch],subtreeDiameter);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0; i<n-1; ++i){
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0,1);
		for(int i=0; i<n+1; ++i) adj[i].clear();
	}
}