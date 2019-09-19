#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
using namespace std;
const ll MAX = (int)2e5+6;
ll tree[4*MAX], A[MAX], mark[MAX];

void push(int v, ll tl, ll tr) {
	 if(mark[v]){
	 	  tree[v]=mark[v];
	 	  if(tl!=tr){
	 	  mark[2*v]=mark[v];
	 	  mark[2*v+1]=mark[v];
	 	}
	 	  mark[v]=0;
	 }
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val) {
	 push(v, tl, tr);
	 if(tl > r || tr < l)
	   return;
	 if(tl>=l && tr<=r){
	 		mark[v] = val;
	 		push(v, tl, tr);
	 		return;
	 }
	 else {
	 		
	 		ll tm = (tl+tr)/2;
	 		update(2*v, tl, tm, l, r, val);
	 		update(2*v+1, tm+1, tr, l, r, val);
	 }	    
}

void query(ll v, ll tl, ll tr) {
	 push(v, tl, tr);
	 if(tl==tr) {
	 	printf("%lld\n", tree[v]);
	  return;
	 }
	 ll tm = (tl+tr)/2;
	 query(v*2, tl, tm);
	 query(2*v+1, tm+1, tr);
}

int main() {
	 memset(tree, 0, sizeof tree);
	 memset(mark, 0, sizeof mark);
	 ll n, q;
	 scanf("%lld %lld", &n, &q);
	 while(q--){
	 	 ll l, r, c;
	 	 scanf("%lld %lld %lld", &l, &r, &c);
	 	 update(1, 1, n, l, r, c);
	 }
	 query(1,1,n);
	 return 0;
}


