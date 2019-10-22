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

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
 
int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  int N,K;
  cin>>N>>K;
  int B[N];
  vector<int> v(N+1), C(N), A(N);
  For(i,0,N) {
    cin>>A[i];
    B[i]=A[i];
    C[i]=A[i]; 
    v[A[i]]=i;
  }

  sort(B,B+N);
  int cnt1 = lis(A);
  if(cnt>=N/2 && K>=N/2) {
    sort(A.begin(),A.end());
    For(i,0,N) cout<<A[i]<<" ";
    cout<<endl;
  }
  else {
     int s = (min(K,36)-1)/4;
     For(i,0,s) {
        A[v[B[N-1-i]]] = A[N-1-i];
        A[v[B[i]]] = A[i];
     }
     For(i,0,s) {
        A[N-1-i] = B[N-1-i];
        A[i] = B[i];
     }

     For(i,0,N) cout<<A[i]<<" ";
     cout<<endl;
  }
  
  return 0;
}
