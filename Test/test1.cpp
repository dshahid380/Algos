#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A[N][3];
	for(int i = 0; i < N; i++) 
	   cin >> A[i][0] >> A[i][1] >> A[i][2];
	
	bool f[3];
	memset(f, true, sizeof f);
	int ans=0, idx;
	for(int i = 0; i < N; ++i) {
		 int ans1=0;
		 for(int j=0; j<3; ++j) {
		 	  if(ans1 < A[i][j] && f[j]) {
		 	  	  ans1 = A[i][j];
		 	  	  idx = j;
				 }    
		 }
		 ans += ans1;
		 memset(f, true, sizeof f);
		 f[idx] = false;	    
	}
	cout<<ans;
	       
	return 0;
}

