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

int n;
const int MAX = 1e5 + 5;
const int logMAX = log2(MAX);
vector<pair<int, int>> adj[MAX];
vector<int> level(MAX);
int par[MAX][logMAX+1], minTable[MAX][logMAX+1], maxTable[MAX][logMAX+1];


void dfs(int ch, int dis=-1, int p = -1){
    par[ch][0] = p;
    if(dis!=-1){
        minTable[ch][0] = dis;
        maxTable[ch][0] = dis;
    }
    for(int i=1; i<=logMAX; ++i){
        if(par[ch][i-1]!=-1){
            par[ch][i] = par[par[ch][i-1]][i-1];
            minTable[ch][i] = min(minTable[ch][i-1],minTable[par[ch][i-1]][i-1]);
            maxTable[ch][i] = max(maxTable[ch][i-1],maxTable[par[ch][i-1]][i-1]);
        }
    }

    for(auto x : adj[ch]){
        if(p != x.ff){
            level[x.ff] = level[ch] + 1;
            dfs(x.ff, x.ss, ch);
        }
    }

}

int findLCA(int a, int b){
    if(level[a] > level[b]){
        swap(a,b);
    }
    int d = level[b] - level[a];
    while(d > 0){
        int i = log2(d);
        b = par[b][i];
        d -= (1<<i);
    }

    if(a == b)
        return a;
    for(int i = logMAX; i>=0; i--){
        if(par[a][i]!=-1 && par[a][i]!=par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

pair<int, int> getMinMaxPair(int ch, int p){
    if(ch == p)
        return {0, 0};

    int d = level[ch] - level[p];
    pair<int, int> ans = {INT_MAX, INT_MIN};
    while(d > 0){
        int i = log2(d);
        ans.ff = min(ans.ff, minTable[ch][i]);
        ans.ss = max(ans.ss, maxTable[ch][i]);
        ch = par[ch][i];
        d -= (1<<i);
    }
    return ans;
}

pair<int, int> query(int u, int v){
    int l = findLCA(u, v);
    if(u==l){
        return getMinMaxPair(v, l);
    }else if(v==l){
        return getMinMaxPair(u, l);
    }

    pair<int, int> p = getMinMaxPair(u, l), q = getMinMaxPair(v, l);
    return {min(p.ff, q.ff), max(p.ss, q.ss)};
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
    // cin>>t;
    while(t--){
        int u, v, c;
        cin>>n;
        memset(par, -1, sizeof(par));
        rep(i,1,n+1){
            rep(j,0,logMAX+1){
                minTable[i][j] = INT_MAX;
                maxTable[i][j] = INT_MIN;
            }
        }
        rep(i, 0, n-1){
            cin>>u>>v>>c;
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        dfs(1);
        int q;
        cin>>q;
        while(q--){
            cin>>u>>v;
            pair<int, int> ans = query(u,v);
            cout<<ans.ff<<" "<<ans.ss<<endl;
        }
        
    }

    return 0;
}
        
        















