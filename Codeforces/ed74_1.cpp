#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int 
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
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define mod 1000000007 
#define Judge


int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  freopen("input1.in","w",stdout);
  int t = 10; 
  cout<<t<<endl;
  while(t--) {
     int n = rand()%10+1, x;
     cout<<n<<endl;
     for(int i=0; i<n; i++) {
        x = rand()%20+1;
        cout<<x<<" "; 
     }
     cout<<endl;
  }
  return 0;
} 
