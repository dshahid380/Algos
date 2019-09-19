/*
Problem Link : https://www.codechef.com/problems/FIRESC
Solution by : Md Shahid
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vii vector<vector<int>>
#define vi vector<int>
#define MOD 1000000007
ll cnt;
vector<bool> visited(100005);
vii adj(100005);

void dfs(int s) {
	  visited[s] = true;
	  cnt++;
	  //cout<<s<<" ";
	  for(auto x: adj[s]) {
	  	 if(!visited[x]) {
	  	 	  dfs(x);
			 }
		}
}

int main() {
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 
	 int T;
	 scanf("%d",&T);
	 while(T--) {
	 	  int n,m;
	 	  scanf("%d %d", &n, &m);
	 	  visited.assign(n+1, false);
	 	  for(int i=0; i<m; i++) {
	 	  	  int a, b;
	 	  	  scanf("%d %d", &a, &b);
	 	  	  adj[a].push_back(b);
	 	  	  adj[b].push_back(a);
			 } 
			 int comp =0; ll ans = 1;
			 for(int i=1; i<=n; i++) {
			 	  if(!visited[i]) {
			 	  	  comp++;
			 	  	  //cout<<i<<" ";
			 	  	  cnt = 0;
			 	  	  dfs(i);
			 	  	  ans = (ans*cnt)%MOD;
					 }
			 }
	 	 printf("%d %d\n",comp,ans);
	 	 visited.clear();
	 	 for(int i=1; i<=n; i++) adj[i].clear();
	 }
	 return 0;
}

