#include<bits/stdc++.h>
using namespace std;
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
const ll MOD = 1e9 + 7;

ll a1, b1, a2, b2;

map<pair<ll, ll>, ll> dp;

ll dfs(ll x1, ll y1, ll x2, ll y2, ll cost=0){
    // cout << x1 << " " << y1 << endl;
    if(x1 == x2 && y1 == y2){
        // cout << "Yes" << endl;
        return cost;
    }

    if(abs(x1-x2)>=50 || abs(y1 - y2)>=50 || cost >=20)
        return INT_MAX;
    
    // if(dp.find({x1,y1})!= dp.end()){
    //     return dp[{x1,y1}];
    // }
    ll south = INT_MAX, north = INT_MAX, east = INT_MAX, west = INT_MAX;
    if(x1 + 2*y1 != x1)
        east = dfs(x1 + 2*y1, y1, x2, y2, cost + 1);

    if(x1 - 2*y1 != x1)
        west = dfs(x1 - 2*y1, y1, x2, y2, cost + 1);


    if(y1 + 2*x1 > 0){
        if(y1 + 2*x1 != y1)
            north = dfs(x1, y1 + 2*x1, x2, y2, cost + 1);
    }else if(y1 + 2*x1 < 0){
        if(-(y1 + 2*x1) != y1)
            north = dfs(-x1, -(y1 + 2*x1), x2, y2, cost + 1);
    } 

    if(y1 - 2*x1 > 0){
        if(y1 - 2*x1 != y1)
            south = dfs(x1, y1 - 2*x1, x2, y2, cost + 1);
    }else if(y1 - 2*x1 < 0){
        if(-(y1 -2*x1) != y1)
            south = dfs(-x1, -(y1 - 2*x1), x2, y2, cost + 1);
    }

    // dp[{x1, y1}] = 
    return min({east, west, south, north}); 
    // return dp[{x1, y1}];
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif
    int t=1;    
    cin>>t;
    while(t--){
        cin >> a1 >> b1 >> a2 >> b2;
        dp.clear();
        cout << dfs(a1, b1, a2, b2)<< endl;
        //cout << dp[{a1,b1}] << endl;
    }
  return 0;
 }















