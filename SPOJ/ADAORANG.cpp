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

int n, q, r;
const int MAX = 6e5 + 5;
const int logMAX = log2(MAX);
vector<int> adj[MAX], level(MAX);
int par[MAX][logMAX+1], shadesCount[MAX+1][252], shades[MAX];

void dfs(int ch, int p = -1){
    par[ch][0] = p;
    shadesCount[ch][shades[ch]]++;
    for(int i = 1; i<=logMAX; i++){
        if(par[ch][i-1] != -1){
            par[ch][i] = par[par[ch][i-1]][i-1];
        }
    }

    for(int x : adj[ch]){
        if(p != x){
            level[x] = level[ch] + 1;
            dfs(x, ch);
            for(int i = 1; i<=251; i++){
                shadesCount[ch][i] += shadesCount[x][i];
            }
        }
    }
    
}

int findLCA(int a, int b){
    if(level[a] > level[b])
        swap(a, b);
    for(int i = logMAX; i >= 0; i--){
        if(level[b] - (1<<i) >= level[a])
            b = par[b][i];
    }
    if(a==b)
        return a;
    for(int i = logMAX; i >= 0; i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

int query(int x, int y){
    int ans = 0;
    int lca = findLCA(x, y);
    for(int i = 1; i<251; i++){
        if(shadesCount[lca][i])
            ans++;
    }
    return ans;

}

void init(){
    for(int i = 0; i<n; i++){
        adj[i].clear();
        level[i] = 0;
        for(int j = 1; j<=251; j++)
            shadesCount[i][j] = 0;
        for(int j = 0; j<=logMAX; j++)
            par[i][j] = -1;
    }
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r",stdin);
        freopen("output.in", "w",stdout);
    #endif
    int t=1;    
    cin>>t;
    while(t--){
        cin >> n >> q >> r;
        init();
        for(int i = 0; i < n; i++){
            cin >> shades[i];
        }
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(r);
        while(q--){
            int x, y;
            cin >> x >> y;
            cout << query(x, y) << endl;
        }
    }

    return 0;
}
        
        















