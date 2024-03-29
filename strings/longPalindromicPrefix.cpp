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

string longPalindrome(string s){
    string res = s+"#";
    reverse(s.begin(),s.end());
    res += s;
    vector<int> f(res.size()+4);
    int j = 0;
    for(int i=1;i<res.size();i++){
        //int j = f[i-1];
        while(res[i] != res[j] && j>0){
            j = f[j-1];
        }
        if(res[i] == res[j]){
            j++;
        }
        f[i] = j;
        //cnt = max(cnt,j);
    }
    return res.substr(0,j);
 
}

int main() { 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  
  return 0;
}
