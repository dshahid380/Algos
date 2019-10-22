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
     int A[n];
     vvi v(1000005);
     umap<int,int> d;
     For(i,0,n) {
          cin>>A[i];
          v[A[i]].pb(i);
          d[A[i]]=i;
     } 
     vi dp(maxarr(A)+2,0);     
     For(i,0,n) {
        umap<int,int> st;
        For(j,1,sqrt(A[i])+1) {
           if(A[i]%j==0) {
               if(A[i]/j==j && A[i]!=j && v[j].size()>0) {
                    int tmp = v[j][v[j].size()-1];
                    if(tmp>i)
                        st[j]=j;  
               }   
               else{
                    int t = A[i]/j;
                    if(A[i]!=t && v[t].size()>0) {
                        int tmp1 = v[t][v[t].size()-1];
                        if(tmp1>i)
                            st[t]=t;
                    }
                    if(A[i]!=j && v[j].size()>0) {
                        int tmp2 = v[j][v[j].size()-1]; 
                        if(tmp2>i)
                            st[j]=j;
                    }
                } 
            }            
        }
        for(auto x : st)
           dp[x.first]++;
     }
      for(auto x : d)
         dp[x.first]+=v[x.first].size()-1;
      cout<<maxvec(dp)<<"\n";   
  }
  return 0;
}
