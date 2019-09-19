#include<bits/stdc++.h> 
#define ll long long int 
#define vi vector<ll>
#define mod 1000000007 
using namespace std;


int main() {
	 ll T;
	 cin>>T;
	 while(T--) {
	 	 ll A, B, C, cnt=0;
	 	 cin>>A>>B>>C;
	 	 vi AC, sqrB;
	 	 ll len_A = min(5002LL,A);
	 	 ll len_C = min(5002LL,C);
	 	 for(ll a=2;a<=len_A; a++) {
	 	 	  for(ll c=2; c<=len_C; c++) {
	 	 	  	 AC.push_back((a-1)*(c-1));
				}
		  }
		  vector<ll>::iterator m;
		  sort(AC.begin(), AC.end());
		  ll len_AC = AC.size();
		  for(ll b=1; b<=B; b++) {
		  	  m = upper_bound(AC.begin(), AC.end(),b*b);
		  	  //cout<<"m ="<<m<<" ";
		  	  cnt += len_AC - (m - AC.begin());
		  	  cnt = cnt%mod;
			}
		  cnt += (max(0LL,A-len_A)*max(0LL,C-len_C))%mod;
		  cout<<cnt<<"\n";
	 }
	 return 0;
}
