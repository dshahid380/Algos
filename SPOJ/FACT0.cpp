#include<bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
using namespace std;

void trialDivision(ll n) {
	unordered_map<ll,ll> fact;
	while(n % 2 == 0) {
		fact[2]++;
		n /= 2;
	}
	for(ll d = 3; d * d <= n; d += 2){
		while(n % d == 0){
			fact[d]++;
			n /= d;
		}
	}
	if(n > 1)
	   fact[n]++;
	   
	vi temp;
	for(auto x: fact)
	   temp.push_back(x.first);
	
	sort(temp.begin(), temp.end());
	for(ll i=0; i<temp.size(); i++){
		cout<<temp[i]<<"^"<<fact[temp[i]]<<" ";
	}
	cout<<endl;		   	
} 

int main() {
	while(true) {
		ll n;
		cin>>n;
		if(n==0)
		   break;
		trialDivision(n);
	}
	return 0;
}
