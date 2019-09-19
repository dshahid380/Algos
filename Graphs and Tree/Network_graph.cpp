#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<ll>
#define mp make_pair
#define vii vector<vecto<int>>
const int MAX = (int)1e6+5;
vii adj(MAX);
int ans;
int bfs(nd,t,n) {
	 queue<int> q;
	 vector<bool> v(false,n);
	 q.push(nd);
	 v[nd]=true;
	 while(!q.empty()) {
	 	  int v = q.front();
	 	  q.pop()
	 	  for(auto x : adj[nd]) {
	 	  	  
			}
	 }
}


int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int n,e,q;
	cin>>n>>e;
	for(int i=0; i<e; i++){
		 int a,b;
		 cin>>a>>b;
		 adj[a].push_back(b);
		 adj[b].push_back(a);	 
	}
	cin>>q;
	while(q--){
		 int nd, t;
		 ans=0;
		 cin>>nd>>t;
		 bfs(nd,t,n);
		 cout<<ans<<endl;
	}
	
	return 0;
}
