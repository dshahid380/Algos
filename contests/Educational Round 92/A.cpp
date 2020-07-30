#include<bits/stdc++.h>
using namespace std;

//Abbreviation of types
#define ull unsigned long long int
#define ll long long int
#define vi vector<int> 
#define vl vector<ll> 
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pair<ll,ll>>
#define umap unordered_map
#define uset unordered_set
#define pb push_back 
#define ff first 
#define ss second

//Abbreviation of operations
#define all(c) c.begin(), c.end()
#define maxarr(A) *max_element(A, A+n) 
#define maxvec(v) *max_element(all(v)) 
#define minarr(A) *min_element(A, A+n);
#define minvec(v) *min_element(all(v));
#define lb(v,elem) lower_bound(all(v),elem)
#define ub(v,elem) upper_bound(all(v),elem)
#define sz(z) (int)z.size()

//Abbreviation of loops
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rev(i,a,b) for(int i=a; i>=b; i--)

//Taking inputs
#define readarray(a,n) rep(i,0,n) cin>>a[i];
#define print(a,n) rep(i,0,n) cout<<a[i]<<" ";cout<<endl;

//Fast IO
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//Debugging tools 
#define debug(v) cout<<#v<<endl;for(ll i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
#define debugn(v,n) cout<<#v<<endl;for(ll i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;
#define printset(s) for(auto it=s.begin; it!=s.end(); it++) cout<<*it<<" ";cout<<endl;
#define deb(sum) cout<<#sum<<" = "<<sum<<endl;

//Predefined values
#define mod 998244353
#define INF (ll)1e18
#define endl "\n"
#define pi 3.142857142857143

ll binpow(ll a, ll b) { if (b == 0) return 1; ll res = binpow(a, b / 2);if (b % 2) return res * res * a;else return res * res;}
ll modexpo(ll x, ll y, ll p){ ll res = 1;  x = x % p; if (x == 0) return 0; while (y > 0){  if (y & 1)  res = (res*x) % p;  y = y>>1;x = (x*x) % p; } return res%mod;}
ll modmul(ll a, ll b){ ll res = 0;a = a%mod;while(b>0){if(b%2==1)res = (res + a)%mod;a = (a<<1) % mod;b = b>>1;}return res % mod;}
ll modmulinv(ll a){ll v = 0, u = 1,md = mod;if(md==1) return 0;while(a>1){ll d = a/md;ll t = md;md = a % md;a = t;t = v;v = u - d * v;u = t;}if(u<0) u += mod;return u;}
vector<int> getPrimes(int M){vi p(M+1,1);vector<int>prime;for(int i=2; i*i <= M; ++i){if(p[i]){for(int j = i*i; j<=M; j+=i) p[j] = 0;}}rep(i,2,M) if(p[i]) prime.push_back(i);return prime;}

  
int main() { 
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        ll x = r/2;
        if(x<l) cout<<-1<<" "<<-1<<endl;
        else{
            if(r&1) cout<<x<<" "<<r-1<<endl;
            else cout<<x<<" "<<r<<endl;
        }
    }
  return 0;
        
} 








