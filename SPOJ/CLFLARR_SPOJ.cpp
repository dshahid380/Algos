#include<bits/stdc++.h>
using namespace std;
int MAX = 1000002;
vector<int> tree(MAX,0);
vector<int> arr;

void update(int idx, int val, int N) {
	for(; idx < N; idx = idx | (idx + 1))
		tree[idx] += val;
}

void range_update(int l, int r, int val, int N) {
	update(l, val, N);
	update(r+1, -val, N);
}

int query(int r) {
	int res = 0;
	for(; r>= 0; r =(r & (r+1))-1)
		res += tree[r];
	return res;
}

int point_query(int idx) {
	return query(idx)-query(idx-1);
}

void build(int N) {
	for(int i=0; i < N; i++){
		update(i, arr[i], N);
	}
}

int main() {
	int N, M, C;
	cin>>N>>M>>C;
	arr.assign(N, C);
	build(N);
	while(M--){
		char t;
		cin>>t;
		if(t=='Q'){
			int p;
			cin>>p;
			cout<<point_query(p)<<endl;
		}
		else{
			int u, v, k;
			cin>>u>>v>>k;
			range_update(u-1, v-1, k, N);
		}
	}
	
	
	return 0;
}
