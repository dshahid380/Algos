#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vii vector<vector<int>> 
#define INF 100005

const int MAX = (int)1e6+3; 
vii adj(MAX);
vector<bool> used(2003);
bool bfs(int s) {
	 queue<int> q; 
	 q.push(s);
	 vi color(2003,INF);
	 color[s] = 0;
	 used[s] = true;
	 bool flag = true;
	 while(!q.empty() && flag) {
	 	  int v = q.front();
	 	  q.pop();
	 	  for(auto u : adj[v]) {
	 	  	  if(color[u]==INF) {
	 	  	  	  color[u] = 1- color[v];
	 	  	  	  q.push(u);
	 	  	  	  used[u] = true;
					 }
					else if(color[u]==color[v]) {
						  flag = false;
						  break;
					}
			 }
	 }
	 return flag;
}

int main() {
	 int T;
	 cin>>T;
	 for(int t=1; t<=T; t++){
	 	  //cout<<"Scenario #"<<t<<":"<<endl;
	 	  int n,m;
	 	  cin>>n>>m;
	 	  used.assign(n+1,false);
	 	  for(int i=0; i<m; i++) {
	 	  	 int a,b;
	 	  	 cin>>a>>b;
	 	  	 adj[a].push_back(b);
	 	  	 adj[b].push_back(a);
			}
			bool res;
			for(int i=1; i<=n; i++) {
				  if(!used[i])
				     res = bfs(i);
				  if(!res)
				    break;
			}
			cout<<"Scenario #"<<t<<":"<<endl;
			if(res) 
			  cout<<"No suspicious bugs found!"<<endl;
			else
			  cout<<"Suspicious bugs found!"<<endl;
	
			used.clear();
			for(int i=1; i<=n; i++)
			   adj[i].clear();
	 }
}





