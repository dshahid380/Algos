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
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define mod 1000000007 

int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  int T;
  cin>>T;
  while(T--) {
     int N;
     cin>>N;
     if(N%2==0)
        cout<<"NO"<<endl;
     else {
        cout<<"YES"<<endl;
        int A[101][101];
        For(i,1,N+1) {
          int K=N/2;
          For(j,1,N+1) {
             if(i==j)
                A[i][j]=0;
             else if(j>i) {
                if(K>0) {
                  A[i][j]=1;
                  A[j][i]=0;
                  K--;
                }
                else {
                  A[i][j]=0;
                  A[j][i]=1;
                }
             } 
          }
        }
        For(i,1,N+1) {
          For(j,1,N+1) {
            cout<<A[i][j];
          }
          cout<<endl;
        }
     }  

  }
  return 0;
}
