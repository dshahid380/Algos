#include<bits/stdc++.h>
using namespace std;

int main() {
	 ios_base::sync_with_stdio(false); 
   cin.tie(NULL); 
   cout.tie(NULL);	
	 int T;
	 cin>>T;
	 while(T--) {
	 	 int n, cnt=0,mx=0;
	 	 cin>>n;
	 	 int A[n];
	 	 vector<vector<int>> v(1000004);
	 	 for(int i=0; i<n; i++) {
	 	 	   cin>>A[i];
	 	 	   v[A[i]].push_back(i);  
			}
		 int Amax = *max_element(A,A+n);
		 vector<int>dp(Amax+2,0);
		 for(int i=0; i<n; ++i) {
		 	  for(int j=1; j<=sqrt(A[i])+1; ++j) { 
		 	  	 if(A[i]%j==0) { 
		 	  	    if(A[i]/j==j) { 
		 	  	       if(v[j].size()>0) { 
		 	  	          int tmp = v[j].size()- (upper_bound(v[j].begin(), v[j].end(),i) - v[j].begin());
		 	  	          dp[j]+=tmp;
								 }
								 
						 }else {
						 	  int t = A[i]/j;
						 	  if(v[j].size()>0) { 
		 	  	          int tmp = v[j].size()-(upper_bound(v[j].begin(), v[j].end(),i) - v[j].begin());
		 	  	          dp[j]+=tmp;
								}
								if(v[t].size()>0) { 
		 	  	          int tmp = v[t].size()-(upper_bound(v[t].begin(), v[t].end(),i) - v[t].begin());
		 	  	          dp[t]+=tmp;
								}
						 } 
					}
				} 
				cout<<cnt<<" ";
				mx = max(mx,cnt);
				cnt = 0;
		 }	
		 cout<<*max_element(dp.begin(),dp.end())<<"\n";
	 }
	 return 0;
}
