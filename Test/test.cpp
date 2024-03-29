#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<int> 
#define vvi vector<vector<int>>
#define pll pair<ll, ll>
#define vl vector<ll> 
#define vvl vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define umap unordered_map
#define uset unordered_set
#define all(c) c.begin(), c.end()
#define maxarr(A) *max_element(A, A+n) 
#define maxvec(v) *max_element(all(v)) 
#define present(map,elem) map.find(elem)!=map.end()
#define lb(v,elem) (lower_bound(all(v),elem) - v.begin())
#define ub(v,elem) (upper_bound(all(v),elem) - v.begin())
#define pb push_back 
#define mp make_pair
#define For(i,a,b) for(int i=a; i<b; ++i) 
#define mod 1000000007 

int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  int T;
  cin>>T;
  while(T--) {
     int n,cnt=0;
     cin>>n;
     int A[n],cnt=0;
     vvi v(1000005);
     For(i,0,n) {
          cin>>A[i];
          v[A[i]].pb(i);
         } 
         vi dp(maxarr(A)+2,0);
         
         For(i,0,n) {
             umap<int,int> st;
             //cout<<A[i]<<" :: "<<endl;
             For(j,1,sqrt(A[i])+1){
                cnt++;
             } 
                for(auto x : st)
                   dp[x.first]++;
                //cout<<endl;
         }
         For(i,0,maxarr(A)+1) {
              if(v[i].size()>0) 
                 dp[i]+=v[i].size()-1;
         }
         cout<<maxvec(dp)<<"\n";
         //For(i,0,maxarr(A)+1) cout<<dp[i]<<" ";    
         
    }
    return 0;
}
