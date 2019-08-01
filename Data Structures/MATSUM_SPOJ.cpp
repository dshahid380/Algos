#include<bits/stdc++.h>
using namespace std;
int tree[1050][1050], A[1050][1050];

void update(int x, int y, int val, int N){
	for(int i = x; i < N; i = i | (i+1)){
		for(int j = y; j < N; j = j | (j+1)){
			tree[i][j] += val;
		}
	}
}

int sum(int x, int y) {
	int res = 0;
	for(int i = x; i >= 0; i = (i & (i+1))-1) {
		for(int j = y; j >= 0; j = (j & (j+1))-1) {
			res += tree[i][j];
		}
	}
	return res;
}

int query(int x1, int y1, int x2, int y2) {
	int ans = sum(x2, y2) + sum(x1-1, y1-1) - sum(x2, y1-1) - sum(x1-1, y2);
	return ans; 
}

void build(int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
		  update(i, j, A[i][j], N);
	}
}

int main() {
	int N;
	cin>>N;
	for(int i=0; i<N; i++){
	  for(int j=0; j<N; j++) {
	     tree[i][j] = 0;
	     A[i][j] = 0;
	 }
	}
	while(true){
		string t;
		cin>>t;
		if(t=="SUM"){
			int x1, x2, y1, y2;
			cin>>x1>>y1>>x2>>y2;
			cout<<query(x1, y1, x2, y2)<<endl;
		} 
		else if(t=="SET"){
			int x, y, val;
			cin>>x>>y>>val;
			update(x, y, val-A[x][y], N);
			A[x][y]=val;
		}
		else
		   break;
	}
}


