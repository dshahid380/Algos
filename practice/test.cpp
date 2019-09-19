#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007 

 
int main(){
  /*ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);	
  preprocess(); */
  ll T;
  scanf("%lld",&T);
  while(T--) {
  	 int A,B,C;
  	 scanf("%d %d %d", &A, &B, &C);
  	 ll cnt =0;
  	 for(int b=1;b<B+1; b++){
  	 	  cnt += (max(0,C-b-1)*1LL*max(0,A-b-1))%mod;
  	 	  for(int j=2; j<=min(A,b+1); j++)
  	 	      cnt += max(0, C-1-(int)(b*1.0*b)/(j-1))%mod;
  	 	  for(int j=2;j<=min(C,b+1); j++)
  	 	      cnt += max(0,A-1-(int)(b*1.0*b)/(j-1))%mod;
		 }
		 printf("%lld\n",cnt%mod);	 
	}
  return 0;	
} 
