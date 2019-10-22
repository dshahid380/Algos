#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<int> 
#define vvi vector<vector<int>>
#define pll pair<ll, ll>
#define vl vector<ll> 
#define vvl vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define ff first
#define ss second
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
const int MAX = 100005;
int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  int T;
  cin>>T;
  while(T--) {
     int n,k,A[MAX]={0},maxx=0;
     cin>>n>>k;
     vector<pair<int,int>> query;
     For(i,0,n) {
        int x,y;
        cin>>x>>y;
        query.pb({x,y});
        A[x]++;
        A[y+1]--;
        maxx = max(y,maxx);
     }
     For(i,2,MAX) {
        A[i] += A[i-1];
     }
     int B[MAX]={0},C[MAX]={0},cnt=0;
     For(i,1,MAX) {
        if(A[i]==k) 
           B[i] = B[i-1]+1;
        else 
           B[i] = B[i-1]; 
        if(A[i]==k+1) 
           C[i] = C[i-1]+1;
        else 
           C[i] = C[i-1];
     }
     for(auto q : query) {
        cnt = max(cnt,C[q.ss]-C[q.ff-1]+B[maxx]-B[q.ss]+B[q.ff-1]);
     }
     cout<<cnt<<endl;
  }
  return 0;
}
