#include<bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000 
#define VISITED 1
#define UNVISITED -1
using namespace std;

// DFS
vi dfs_num;

void dfs(int u) {
	dfs_num[u]=VISITED;
	for(int j=0; j< (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if(dfs_num[v.first]==UNVISITED)
		    dfs(v.first);
	}
}

// Topological Sort
vi ts;

void dfs1(int u) {
	dfs_num[u] = VISITED;
	for(int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		if(dfs_num[v.first]==UNVISITED) {
			dfs1(v.first);
		}
	}
	ts.push_back(u);
}

// Bipartile Graph Check
bool bipartile(ii AdjList, int s) {
	queue<int> q;
	q.push(s);
	vi color(V, INF);
	color[s] = 0;
	bool isBipartile = true;
	while(!q.empty() & isBipartile) {
		int u = q.front();
		q.pop();
		for(int j = 0; j < (int)AdjList[u].size(); j++) {
			ii v = AdjList[u][j];
			if(color[v.first]==INF) {
				color[v.first] = 1 - color[u];
				q.push(v.first);
			}
			else if(color[v.first]==color[u]) {
				isBipartile = false;
				break;
			}
		}
	}
	
}


