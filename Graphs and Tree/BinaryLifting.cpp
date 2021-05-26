#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int n;
connt int logMAX = log2(MAX);
vector<int> adj[MAX], level(MAX);
int par[MAX][logMAX];

void dfs(int ch, int p=-1){
	par[ch][0] = p;
	for(int x : adj[ch]){
		if(p != x){
			level[x] = level[ch] + 1;
			dfs(x, ch);
		}
	}
}

void init(){
	dfs(1);
	for(int j=1; j<=logMAX; j++){
		for(int i = 1; i<=n; i++){
			if(par[i][j-1]!=-1){
				int p = par[i][j-1];
				par[i][j] = par[p][j-1];
			}
		}
	}
}

int findLCA(int a, int b){
	if(level[a] > level[b]){
		int tmp = a;
		a = b;
		b = a;
	}
	int d = level[b] - level[a];
	while(d>0){
		int i = log2(d);
		b = par[b][i];
		d -= (1<<i);
	}

	if(a == b) return a;

	for(int i = logMAX; i>=0; i--){
		if(par[a][i] != -1 && par[a][i] != par[b][i]){
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

int main(){
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	init();
	int x, y;
	cin >> x >> y;
	cout << findLCA(x, y) << endl;
	return 0;
}















