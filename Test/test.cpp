#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main() {
    int T;
    while(T--){
        ll n; 
        cin>>n;
        ll A[n][n];
        for(ll i=0; i<n; i++)
            for(ll j=0; j<n; j++)
                cin>>A[i][j];
        ll dp[n+1][n+1];
        memset(dp,0, sizeof dp);
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]) + A[i][j];
            }
        }
        cout<<dp[n][n]<<"\n";
    }
    return 0;
}