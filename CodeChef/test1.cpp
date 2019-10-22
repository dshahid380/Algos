#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<int> 
#define vvi vector<vector<int>>
#define pll pair<ll, ll>
#define vl vector<ll> 
#define vvl vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define ff first
#define ss second
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
#define sz(v) v.size()
#define For(i,a,b) for(int i=a; i<b; ++i) 
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define mod 1000000007 
const int MAX = 100005;

vl factorize(ll n) {
   vl factors;
   for(ll i=2; i*i<=n; i++) {
      if(n%i==0) {
         factors.pb(i);
         while(n%2==0) 
            n = n/i;
      }
   }
   if(n>1)
      factors.pb(n);
   return factors;
} 

ll modexp(ll x, ll y) {
   ll res = 1;
   x = x%mod;
   while(y>0) {
      if(y&1) 
         res = (res*x)%mod;
      y = y>>1;
      x = (x*x)%mod;
   }
   return res;
}

int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  ll c,n;
  cin>>c>>n;
  vl p = factorize(c);
  ll res = 1;
  rep(i,0,sz(p)) {
     ll p1 = p[i];
     ll x = 0;
     while(p1<=n) {
        x += n/p1;
        p1 = p1*p[i];
     }
     res =((res%mod)*(modexp(p[i],x)))%mod;
  }
  cout<<res%mod<<endl;
  return 0;
}
