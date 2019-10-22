#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<int> 
#define vvi vector<vector<int>>
#define pll pair<ll, ll>
#define vl vector<ll> 
#define vvl vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define umap unordered_map
#define uset unordered_set
#define all(c) c.begin(), c.end()
#define maxarr(A) *max_element(A, A+n) 
#define maxvec(v) *max_element(all(v)) 
#define present(map,elem) map.find(elem)!=map.end()
#define lb(v,elem) (lower_bound(all(v),elem) - v.begin())
#define ub(v,elem) (upper_bound(all(v),elem) - v.begin())
#define pb push_back 
#define mp make_pair
#define For(i,a,b) for(int i=a; i<b; ++i) 
#define mod 1000000007 

const int MAX = 100005;
int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  int T;
  cin>>T;
  while(T--) {
     int n,m;
     cin>>n>>m;
     vvi adj(MAX);
     For(i,0,m) {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
     }
     if(m%2==0) {
        cout<<1<<endl;
        For(i,1,n+1)
          cout<<1<<" ";
        cout<<endl;
     }
     else {
        vi p(MAX,1);
        int f=0;
        For(i,1,n+1) {
           if(adj[i].size()%2==1) {
              p[i]++;
              f=1;
              break;
           }
        }
        if(f==1) {
           cout<<2<<endl;
           For(i,1,n+1) 
             cout<<p[i]<<" ";
           cout<<endl;
        }
        else {
          For(i,1,n+1) {
            if(adj[i].size()>=2) {
               p[i]++;
               p[adj[i][0]]+=2;
               break;
            } 
          }
         cout<<3<<endl;
         For(i,1,n+1) 
           cout<<p[i]<<" ";
         cout<<endl;
        }
     }
  }
  return 0;
}
