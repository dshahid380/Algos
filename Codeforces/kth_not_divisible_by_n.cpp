#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
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
#define lb(v,elem) lower_bound(all(v),elem)
#define ub(v,elem) upper_bound(all(v),elem)
#define pb push_back 
#define mp make_pair
#define ff first 
#define ss second
#define For(i,a,b) for(int i=a; i<b; ++i) 
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define debug(v) for(ll i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
#define debugn(v,n) for(ll i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;
#define mod 1000000007
#define INF 1000000000
#define endl '\n'

bool cmp(pll a, pll b){
   return a.ss<b.ss;
}

bool cmp1(pll a, pll b){
   return a.ff<b.ff;
}

int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  //freopen("1.in","r",stdin);
  
  int t;
  cin>>t;
  while(t--){
     ll n,k;
     cin>>n>>k;
     ll tm = k/(n-1);
     ll tr = k%(n-1);
     if(tr==0)
       cout<<n*tm-1<<endl;
     else cout<<n*tm + tr<<endl;
  }
  return 0;
} 
