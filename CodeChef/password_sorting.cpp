#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second

bool cmp(pii a, pii b) {
   return a.first>b.first;
}

vector<int> SortUserPasswords(vector<int> rating, vector<string> passwords, int n) {
    unordered_map<string,vector<pair<int,int>>> data;
    for(int i=0; i<n; i++) {
       data[passwords[i]].push_back({rating[i],i+1});
    }
    vector<string> v;
    for(auto x: data) {
       v.push_back(x.first);
    }
    sort(v.begin(),v.end());
    vector<int> ans;
    for(auto x : v) {
       sort(data[x].begin(),data[x].end(),cmp);
       for( auto y : data[x]) {
          ans.push_back(y.second);
       }
    } 
    return ans;
}  

int main() {
  int T;
  cin>>T;
  while(T--) {
     int n;
     cin>>n;
     vector<string> v(n);
     vector<int> r(n);
     for(int i=0; i<n; i++) {
       cin>>v[i]>>r[i];
     }
     vector<int> ans(n);
     ans = SortUserPasswords(r,v,n);
     for(int i=0; i<n; i++) cout<<ans[i]<<endl;
     //cout<<endl; 
  }
  return 0;
}