#include<bits/stdc++.h>
#define ll long long int 
#define pii pair<ll, ll>
using namespace std;
const ll MAX = 100006;
pii tree[4*MAX];
ll A[MAX];

pii count_pair(pii a, pii b) {
	if(a.first > b.first)
		return a;
	if(b.first > a.first)
		return b;
	return make_pair(a.first, a.second+b.second);
}

void build(ll v, ll tl, ll tr) {
	if(tl==tr)
		tree[v] = make_pair(A[tl], 1);
	else {
		ll tm = (tl+tr)/2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
		tree[v] = count_pair(tree[v*2],tree[2*v+1]);
	}
}

pii getMax(ll v, ll tl, ll tr, ll l, ll r) {
	if(l>r)
		return make_pair(-999,0);
	if(l==tl && r==tr)
		return tree[v];
	ll tm = (tl+tr)/2;
	return count_pair(getMax(v*2, tl, tm, l, min(r, tm)),
		              getMax(2*v+1, tm+1, tr, max(l,tm+1), r));

}

void update(ll v, ll tl, ll tr, ll pos, ll val) {
	if(tl==tr)
		tree[v] = make_pair(val, 1);
	else {
		ll tm = (tl+tr)/2;
		if(pos <= tm)
			update(2*v, tl, tm, pos, val);
		else 
			update(2*v+1, tm+1, tr, pos, val);
		tree[v] = count_pair(tree[2*v], tree[2*v+1]);
	}
}

int main() {
	ll T;
	cin>>T;
	while(T--){
		ll N, Q;
		cin>>N>>Q;
		for(ll i=0; i<N; i++) cin>>A[i];
		build(1, 0, N-1);
	    while(Q--){
	    	char op;
	    	cin>>op;
	    	if(op=='F'){
	    		ll l, r;
	    		cin>>l>>r;
	    		l--;
	    		r--;
	    		pii x = getMax(1, 0, N-1, l, r);
	    		cout<<"Max : "<<x.first<<" Max count : "<<x.second<<endl;
			 }
			 else {
			 	 ll pos, val;
			 	 cin>>pos>>val;
			 	 update(1,0, N-1, pos-1, val);
			 } 
	    }
	}
	return 0;
}
