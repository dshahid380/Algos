#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<ll>
#define pii <ll, ll>

int main() {
	 int T;
	 cin>>T;
	 string ch[] = {"a","b","c","d","e","f","g","h"};
	 unordered_map<string,vector<string>> adj;
	 unordered_map<string,bool> visited;
	 unordered_map<string,int> distance;
	 for(int i=0; i<8;i++){
	 	  for(int j=0; j<8; j++){
	 	  	  visited[ch[i]+to_string(j+1)]=false;
	 	  	  distance[ch[i]+to_string(j+1)]=0;
	 	     	for(int k=0; k<8; k++){
	 	     	   for(int l=0; l<8; l++){
	 	     	   	   if(((i-k)*(i-k)+(j-l)*(j-l))==5){
	 	     	   	   	  adj[ch[i]+to_string(j+1)].push_back(ch[k]+to_string(l+1));
								}
						 }	
					}
		  }	     
	 }
	 
	 while(T--) {
	 	  unordered_map<string, bool> used;
	 	  used = visited;
	 	  queue<string> q;
	 	  string s, d;
	 	  cin>>s>>d;
	 	  q.push(s);
	 	  used[s]=true;
	 	  unordered_map<string,int> dis;
	 	  dis[s]=0;
	 	  int f=0;
	 	  while(!q.empty()) {
	 	  	 string v = q.front();
	 	  	 //cout<<v<<endl;
				 q.pop();
				 for(auto u : adj[v]) {
				 	  if(!used[u]) {
				 	  	  used[u]=true;
				 	  	  q.push(u);
				 	  	  dis[u] = dis[v]+1;
				 	  	  //cout<<dis[u]<<endl;
				 	  	      			 	  	  
						}
				 }
					  
			}
			cout<<dis[d]<<endl;
	 }
	 return 0;
	 
}
