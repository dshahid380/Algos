#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define mod 1000000007
ll dp[100003][103];


void pre() {
    for(ll n=1; n<100003; n++) {
        for(ll k=1; k<103; k++ ){
            if(n==1) 
              dp[n][k]=k;
            else if(n==2)
              dp[n][k] = (k + k*(k-1))%mod;
            else 
              dp[n][k] =((dp[n-1][k]+dp[n-2][k])*(k-1))%mod;
        }
    }
}

int main() {
    pre();
    int T;
    cin>>T;
    while(T--) {
        ll N, K;
        cin>>N>>K;
        cout<<dp[N][K]<<endl;
        
    }
}