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
#define debug(v) cout<<#v<<endl;for(ll i=0; i<sz(v); i++) cout<<v[i]<<" "; cout<<endl;
#define debugn(v,n) cout<<#v<<endl;for(ll i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;
#define deb(sum) cout<<#sum<<" = "<<sum<<endl;
//Predefined values
#define INF (ll)1e18
#define endl "\n"
#define pi 3.142857142857143
const ll MOD = 998244353;

ll maxPowerOfTwo(ll n){
    for(int i = 30; i >= 0; i--){
        if(n & (1<<i))
            return (1<<i);
    }
    return 0;
}

ll compressSegment(multiset<ll> v){
    while(sz(v)>=2){
        auto it = v.rbegin();
        ll n1 = *it;
        v.erase(v.find(n1));
        it++;
        ll n2 = *it;
        v.erase(v.find(n2));
        ll xr = n1 ^ n2;
        v.insert(maxPowerOfTwo(xr));
        // for(int x : v)
        //     cout << x << " ";
        // cout << endl;
    }
    return *v.begin();
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
    //cin>>t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            // a[i] = maxPowerOfTwo(a[i]);
        }
        // ll ans = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         multiset<ll> tm;
        //         for(int k = i; k <= j; k++){
        //             tm.insert(a[k]);
        //             cout << a[k] << ' ';
        //         }
        //         cout << endl;
        //         // cout << i << ", " << j << ": "<<endl;
        //         cout << compressSegment(tm) << endl;
        //         ans += compressSegment(tm);
        //         ans %= MOD;
        //     }
        // }
        // cout << ans << endl;

        multiset<ll>v;
        v.insert(5);
        v.insert(6);
        v.insert(6);
        cout << compressSegment(v) << endl;
    }
    return 0;
}
        












