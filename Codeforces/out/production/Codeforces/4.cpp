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
const ll MOD = 2;

const int MAX = 2e5 + 5;
ll dp[2][MAX];
ll sum[MAX];
vector<ll> twocnt(2*MAX);


ll nCr(ll n, ll r){
    if(twocnt[n]-twocnt[n-r] > twocnt[r])
        return 0;
    else
        return 1;
}

int nCrModpDP(int n, int r, int p) 
{ 
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (int i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous 
        // row values 
        for (int j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 

int nCrModpLucas(int n, int r, int p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
   // Compute last digits of n and r in base p 
   int ni = n%p, ri = r%p; 
  
   // Compute result for last digits computed above, and 
   // for remaining digits.  Multiply the two results and 
   // compute the result of multiplication in modulo p. 
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
} 


int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif

    int MAXK = 200000;
    
    dp[0][0] = 1;
    sum[0] = 1;
    
    int prev = 0;
    int next = 1;
    
    rep(i,1,400)
    {
        memset(dp[next], 0 , sizeof dp[next]);
        rep(j,i,MAXK + 1)
        {
            dp[next][j] = (dp[next][j - i] + dp[prev][j - i]) % MOD;
            if (i % 2 == 0)
            {
                sum[j] += dp[next][j]%MOD;
                sum[j] %= MOD;
            }
            else
            {
                sum[j] -= dp[next][j]%MOD;
                if (sum[j] < 0) sum[j] += MOD;
            }
        }
        swap(prev , next);
    }

    for(int i = 1; i < 2*MAX; i++){
        int x = i;
        while(x%2==0){
            twocnt[i]++;
            x /= 2;
        }
        twocnt[i] += twocnt[i-1];
    }

    int t=1;    
    cin>>t;
    while(t--){
        ll n , k;
        cin >> n >> k;
        ll res = 0;
        rep(i,0,k + 1)
        {
            res += (sum[i] * nCrModpLucas(n-1+i, i, MOD)) % MOD;
            res %= MOD;
            // cout << nCr(n-1+i, i) << endl;
        }
        
        cout << res << endl;
        
    }
    // cout << twocnt[8] << endl;
    // cout << nCr(4,2) << endl;
  return 0;
 }















