#include<bits/stdc++.h>
using namespace std;

//Abbreviation of types
#define ull unsigned long long int
#define ll long long int
#define ld long double
#define pb push_back 
#define ff first 
#define ss second
#define all(c) c.begin(), c.end()
#define sz(z) (int)z.size()
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rev(i,a,b) for(int i=a; i>=b; i--)
//Debugging tools 
#define debug(v) cout<<#v<<endl;for(ll i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
#define debugn(v,n) cout<<#v<<endl;for(ll i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;
#define deb(sum) cout<<#sum<<" = "<<sum<<endl;
//Predefined values
#define INF (ll)1e18
#define endl "\n"
#define pi 3.142857142857143

ll mod =(ll)1e9+7;
vector<ll>fact(1000006);
vector<ll>mul(1000006);
vector<ll>dp(1000006);
ll n;
void init(){
    fact[1] = 1;
    fact[0] = 1;
    for(ll i=1; i<1000006; ++i){
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
    }
    for(ll i=1; i<1000004; ++i){
        if(n>=i+2)
            mul[i] = (fact[i-1]*fact[n-i-2])%mod;
        else
            break;
    }
    for(ll i=1; i<1000004; ++i){
        if(i==1) 
            dp[i] = mul[i];
        else
            dp[i] = (dp[i-1]+mul[i])%mod;
    }
}

int main() { 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        cin>>n;
        
    }
  return 0;
} 















