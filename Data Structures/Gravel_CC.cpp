#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll tree[1000006];
ll N;

void update(ll idx, ll val){
	for(; idx <= N; idx+= idx & (-idx))
		tree[idx] += val;
}

void update_range(ll l, ll r, ll val){
	update(l, val);
	update(r+1, -val);
}

ll query(ll idx){
	ll ans = 0;
	for(;idx>0; idx -= idx & (-idx))
		ans += tree[idx];
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	memset(tree, 0, sizeof tree);
	ll M, C;
	scanf("%lld %lld %lld", &N, &M, &C);
	while(M--){
		char t[3];
		scanf("%s", &t);
		if(t[0]=='S') {
			ll u, v, k;
			scanf("%lld %lld %lld", &u, &v, &k);
			update_range(u, v, k);
		}
		else {
			ll p;
			scanf("%lld", &p);
			printf("%lld\n", query(p)+C);
		}
	}
	return 0;
}

