#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
vector<int> adj[MAX], dis(MAX), par(MAX);

void dfs(int ch, int p){
	par[ch] = p;
	for(int x : adj[ch]){
		if(x != p){
			dis[x] = dis[ch] + 1;
			dfs(x,ch);
		}
	}
}

// Brute force approach.
int LCA(int a, int b){
	int d = dis[b] - dis[a];
	while(d > 0){
		b = par[b];
		d--;
	}
	if(a == b)
		return a;

	while(par[a] != par[b]){
		a = par[a];
		b = par[b];
	} 
	return par[a];
}

int main(){
	cin>>n;
	for(int i = 0; i<n-1; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int x,y;
	cin>>x>>y;
	dfs(0,1);
	if(dis[x]>dis[y]){
		cout<<LCA(y,x)<<endl;
	}else
		cout<<LCA(x,y)<<endl;
}