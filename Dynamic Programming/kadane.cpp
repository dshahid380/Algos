#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define INF 1000000000 
#define VISITED 1
#define UNVISITED -1
using namespace std;

int max_sub_array_sum(int A[]) {
	int max_so_far = -INF;
	int max_ending_here = 0;
	
	for(int i = 0; i < A.size(); i++) {
		max_ending_here = max_ending_here + A[i];
		if(max_so_far < max_ending_here) 
		    max_so_far = max_ending_here;
		if (max_ending_here < 0)
		    max_ending_here = 0; 
	}
	return max_so_far;
}

int main() {
	int T, N;
	cin>>T;
	while(T--) {
		int A[100];
		cin>>N;
		for(int i = 0; i< N; i++ ) cin>>A[i];
		cout<<max_sub_array_sum(A)<<endl;
	}
	return 0;
}










