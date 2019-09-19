#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pii pair<ll, ll> 
#define vi vector<ll> 
const ll MAX = (ll)1e6;
ll A[MAX], t[4*MAX];
pii tree[4*MAX];

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void build2(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = A[tl];
    } else {
        int tm = (tl + tr) / 2;
        build2(v*2, tl, tm);
        build2(v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

pii combine(pii a, pii b) {
	 if(a.first > b.first)
	    return make_pair(a.first, a.second+b.second);
	 else 
	    return make_pair(b.first, a.second+b.second);
	    
}

pii combine2(pii a, pii b, ll Y) {
	 if(a.first<=Y && b.first<=Y)
	    return make_pair(a.first, a.second+b.second);
	 else if(a.first <=Y && b.first>Y)
	    return a;
	 else if(a.first >Y && b.first<=Y)
	    return b;
	 else 
	    return make_pair((ll)-1,(ll)0); 
	    
}

void build(ll v, ll tl, ll tr) {
	 if(tl==tr) {
	 	 tree[v] = make_pair(A[tl],A[tl]);
	 } else {
	 	   ll tm = (tl+tr)/2;
	 	   build(2*v, tl, tm);
	 	   build(2*v+1,tm+1,tr);
	 	   tree[v] = combine(tree[2*v],tree[2*v+1]);
	 }
}

pii get(ll v, ll tl, ll tr, ll l, ll r, ll Y) {
	 if(l > r)
	    return make_pair((ll)0,(ll)0);
	 if(l==tl && r==tr && tree[v].first<=Y)
	 	  return tree[v];
	 ll tm = (tl+tr)/2;
	 return combine(get(2*v, tl, tm, l, min(r,tm), Y), get(2*v+1, tm+1,tr, max(l, tm+1),r, Y));
	 
	 }


int main() {
	 ll n,q;
	 cin>>n;
	 for(ll i=0; i<n; i++) cin>>A[i];
	 build2(1,0,n-1);
	 build(1,0,n-1);
	 cin>>q;
	 while(q--){
	 	  ll l,r,y;
	 	  cin>>l>>r>>y;
	 	  ll res = get(1,0,n-1,l-1,r-1,y).second;
	 	  if(res>=y)
	 	    cout<<res<<endl;
	 	  else
	 	    cout<<-1<<endl;
	 }
	 return 0;
}

