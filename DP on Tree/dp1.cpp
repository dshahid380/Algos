/*
Problem Statement
-----------------
The first problem we solve is as follows: 
Given a tree T of N nodes, where each node i 
has C i coins attached with it. You have to 
choose a subset of nodes such that no two 
adjacent nodes(i.e. nodes connected directly by an edge)
are chosen and sum of coins attached with nodes in chosen 
subset is maximum.

Source : https://codeforces.com/blog/entry/20935
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;
vector<int> adj[MAX];
int dp1[MAX], dp2[MAX], c[MAX];

void dfs(int p, int ch){
    int tm1 = 0, tm2 = 0;
    for(int u : adj[ch]){
        if(u!=p){
            dfs(ch, u);
            tm1 += dp2[u];
            tm2 += max(dp1[u], dp2[u]);
        }
    }
    dp1[ch] = tm1 + c[ch];
    dp2[ch] = tm2;

}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
        cin>>c[i];
    return 0;
}
