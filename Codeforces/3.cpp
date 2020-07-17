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
ll modmulinv(ll a){ll m = mod, v = 0, u = 1,md = mod;if(md==1) return 0;while(a>1){ll d = a/md;ll t = md;md = a % md;a = t;t = v;v = u - d * v;u = t;}if(u<0) u += mod;return u;}
vector<int> getPrimes(int M){vi p(M+1,1);vector<int>prime;for(int i=2; i*i <= M; ++i){if(p[i]){for(int j = i*i; j<=M; j+=i) p[j] = 0;}}rep(i,2,M) if(p[i]) prime.push_back(i);return prime;}



const int MAX = 200005;
ll n,q;
vl h, a;
vl dpFor(MAX,-1), dpBack(MAX,-1);
vl tree(4*MAX), treeFor(4*MAX), treeBack(4*MAX);
vl nextGreatest(MAX), temp(MAX), prevGreatest(MAX); 
vl nextGreaterEqual(MAX), temp1(MAX), prevGreaterEqual(MAX);

//Preparation for DP arrays
void prepareGreatest() {
   stack<pair<ll,ll>> s;
   s.push({h[0],0});
   rep(i,1,n) {
       if(s.empty()) {
           s.push({h[i],i});
           continue;
       }
       while(!s.empty()&&s.top().ff<h[i])  
           nextGreatest[s.top().ss]=i,s.pop();
       s.push({h[i],i});
   }
   while(!s.empty())
       nextGreatest[s.top().ss]=-1,s.pop();
}

void prepareGreatest1() {
   reverse(all(h));
   stack<pair<ll,ll>> s;
   s.push({h[0],0});
   rep(i,1,n) {
       if(s.empty()) {
           s.push({h[i],i});
           continue;
       }
       while(!s.empty()&&s.top().ff<h[i])  
           temp[s.top().ss]=i,s.pop();
       s.push({h[i],i});
   }
   while(!s.empty())
       temp[s.top().ss]=-1,s.pop();
   reverse(all(h));
}

//Preparation for tree updates
void prepareGreaterEqual() {
   stack<pair<ll,ll>> s;
   s.push({h[0],0});
   rep(i,1,n) {
       if(s.empty()) {
           s.push({h[i],i});
           continue;
       }
       while(!s.empty()&&s.top().ff<=h[i])  
           nextGreaterEqual[s.top().ss]=i,s.pop();
       s.push({h[i],i});
   }
   while(!s.empty())
       nextGreaterEqual[s.top().ss]=-1,s.pop();
}

void prepareGreaterEqual1() {
   reverse(all(h));
   stack<pair<ll,ll>> s;
   s.push({h[0],0});
   rep(i,1,n) {
       if(s.empty()) {
           s.push({h[i],i});
           continue;
       }
       while(!s.empty()&&s.top().ff<=h[i])  
           temp1[s.top().ss]=i,s.pop();
       s.push({h[i],i});
   }
   while(!s.empty())
       temp1[s.top().ss]=-1,s.pop();
   reverse(all(h));
}

//Segtree for finding -1 condition
void build(int v, int tl, int tr){
    if(tl==tr) tree[v] = h[tl];
    else {
        int tm = (tl + tr)>>1;
        build(v<<1, tl, tm);
        build((v<<1)+1, tm+1,tr);
        tree[v] = max(tree[v<<1], tree[(v<<1)+1]);
    }
}

ll getMAX(int v, int tl, int tr, int l, int r){
    if(l>r) return 0;
    if(l==tl && r==tr) return tree[v];
    int tm = (tl + tr)>>1;

    return max(getMAX(v<<1, tl, tm, l, min(r,tm)),
               getMAX((v<<1)+1, tm+1, tr, max(l, tm+1), r));
}

// Prepare dp array for forward and backward
ll solveFor(int i){
    if(dpFor[i]!=-1) return dpFor[i];
    ll res = a[i];
    if(nextGreatest[i]!=-1){
        res += solveFor(nextGreatest[i]);
    }

    dpFor[i] = res;
    return res;
}


ll solveBack(int i){
    if(dpBack[i]!=-1) return dpBack[i];
    ll res = a[i];
    if(prevGreatest[i]!=-1){
        res += solveBack(prevGreatest[i]);
    }
    
    dpBack[i] = res;
    return res;
}

//Segment Tree on Forward DP
void buildForwardTree(int v, int tl, int tr) {
    if (tl == tr) {
        treeFor[v] = dpFor[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildForwardTree(v*2, tl, tm);
        buildForwardTree(v*2+1, tm+1, tr);
        treeFor[v] = 0;
    }
}

void updateFor(int v, int tl, int tr, int l, int r, ll add) {
    if (tr<l || tl>r)
        return;
    if (tl>=l && tr<=r) {
        treeFor[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        updateFor(v*2, tl, tm, l, r, add);
        updateFor(v*2+1, tm+1, tr, l, r, add);
    }
}

void updateForward(int idx, ll val){
    ll diff = val - a[idx];
    a[idx] = val;
    int l = prevGreaterEqual[idx];
    int r = idx;
    updateFor(1,0,n-1,l+1,r,diff);

}

ll getSumFor(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return treeFor[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return treeFor[v] + getSumFor(v*2, tl, tm, pos);
    else
        return treeFor[v] + getSumFor(v*2+1, tm+1, tr, pos);
}

//Fenwick Tree on Backward DP;
void buildBackwardTree(int v, int tl, int tr) {
    if (tl == tr) {
        treeBack[v] = dpBack[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildBackwardTree(v*2, tl, tm);
        buildBackwardTree(v*2+1, tm+1, tr);
        treeBack[v] = 0;
    }
}

void updateBack(int v, int tl, int tr, int l, int r, ll add) {
    if (tr<l || tl>r)
        return;
    if (tl>=l && tr<=r) {
        treeBack[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        updateBack(v*2, tl, tm, l, r, add);
        updateBack(v*2+1, tm+1, tr, l, r, add);
    }
}

void updateBackward(int idx, int val){
    ll diff = val - a[idx];
    a[idx] = val;
    int l = idx;
    int r = nextGreaterEqual[idx];
    if(r==-1) r = n-1;
    else r--;
    updateBack(1,0,n-1,l,r, diff);
}

ll getSumBack(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return treeBack[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return treeBack[v] + getSumBack(v*2, tl, tm, pos);
    else
        return treeBack[v] + getSumBack(v*2+1, tm+1, tr, pos);
}


int main() { 
    FASTIO;
    freopen("fish.in","r",stdin);
    freopen("fishout.out","w",stdout);
    //vi pm = getPrimes(1005);
    int t=1;
    cin>>t;
    while(t--){
        cin>>n>>q;
        a.assign(n,0);
        h.assign(n,0);
        rep(i,0,n) cin>>h[i];
        rep(i,0,n) cin>>a[i];
        vl a1 = a;
        vl h1 = h;

        //Initialize all
        prepareGreatest();
        prepareGreatest1();
        rep(i,0,n){
            if(temp[n-1-i]==-1) prevGreatest[i] = -1;
            else prevGreatest[i] = n-1-temp[n-1-i];
        }

        prepareGreaterEqual();
        prepareGreaterEqual1();
        rep(i,0,n){
            if(temp1[n-1-i]==-1) prevGreaterEqual[i] = -1;
            else prevGreaterEqual[i] = n-1-temp1[n-1-i];
        }

        rep(i,0,n) solveFor(i),solveBack(i);

        build(1, 0, n-1);
        buildForwardTree(1,0,n-1);
        buildBackwardTree(1,0,n-1);
        // debugn(dpFor,n);
        // debugn(dpBack,n);
        // debugn(bitFor,n);
        // debugn(bitBack,n);
        vl ans, ans1;

        while(q--){
            int t, x, y;
            cin>>t>>x>>y;
            if(t==1){
                x--;
                updateForward(x,y);
                updateBackward(x,y);
            }else{
                x--, y--;
                if(x==y){
                    ans.pb(a[x]);
                }else{
                    if(x>y){
                        int maxx = getMAX(1,0,n-1,y,x-1);
                        if(maxx>=h[x] || h[x]<=h[y]){
                            ans.
                            continue;
                        }
                        // deb(getSumFor(y));
                        // deb(getSumFor(x));
                        cout<<getSumFor(1,0,n-1,y) - getSumFor(1,0,n-1,x) + a[x]<<;
                    }else{
                        int maxx = getMAX(1,0,n-1,x+1,y);
                        if(maxx>=h[x] || h[x]<=h[y]){
                            cout<<-1<<endl;
                            continue;
                        }
                        cout<<getSumBack(1,0,n-1,y) - getSumBack(1,0,n-1,x) + a[x]<<endl;
                    }
                }
            }
        }
        
    }

  return 0;
} 















