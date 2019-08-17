#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
int MAX = 100010;
ll power[MAX], multiplier[MAX], base[110];

ll modmult(ll a, ll b){
	ll ans = ((a%M)*(b%M))%M;
	return ans;
}

void preproces(){
	
	//base
	int sm=0;
	base[0]=0;
	for(int i=0;  i<101; i++){
		if(i%11==0)
			sm+= i/11;
		base[i]=sm; 
	}
	
	//power 
	ll product = 1;
	for(ll i=1; i<100010; i++) {
		product = (product * 10)%M;
		power[i] = product;
	}
	
	//Multiplier
	multiplier[0]=1, multiplier[1]=1, multiplier[2]=1;
	multiplier[3]=110;
	for(ll i=4; i<100010; i++){
		multiplier[i] = modmult(multiplier[i-1],100) + power[i-2]
		multiplier[i] %= M 
	}		
}

ll value(ll n, ll p){
	if(p==0)
		return base[n];
	if(p==1)
		return base[n*10];
	if(p==2){
		ll res = (45*n*n + (((n*(n-1))/2)*10))%M;
		return res; 
	}
	ll res = modmult(45*n*n, multiplier[p]) + modmult((n*(n-1))/2,power[p-1]);
    return res;
}

ll remove(vector<ll> l){
	ll siz = l.size();
	ll carry = 0;
	ll ans = value(l[0], n-1);
	for(ll i=1; i<n; i++){
		ll val = value(l[i],n-1-i);
		if(l[i]>l[i-1])
			ans += modmult(l[i-1], modmult(power[n-1-i],power[n-1-i])) + val + modmult(carry,l[i]*power[n-1-i]);
		else if(l[i]<l[i-1])
			ans += val + modmult(carry, l[i]*power[n-1-i]);
		else if(l[i]==l[i-1]){
			ans += val + modmult(carry, l[i]*power[n-1-i]);
			carry += modmult(l[i], power[n-1-i]);
			carry %= M;
		}
	}
	ans += carry;
	ans %= M;
	return ans;
}

vector<int> string_to_array(string s){
	vector<int> l;
	for(int i=0; i<s.size(); i++){
		l.push_back(atoi(s[i]));
	}
	return l;
}

ll mod_num(vector<int> l){
	ll res = 0;
	for(ll i=0; i<l.size(); i++){
		res += l[i]*power[n-i-1];
		res %= M;
	}
	return res;
}

int main() {

	preproces();
	ll T;
	while(T--){
		string nl, nr, L, R;
		cin>>nl>>L;
		cin>>nr>>R;
		vector<int> arrL = string_to_array(L);
		vector<int> arrR = string_to_array(R);
		ll modL = mod_num(arrL);
		ll modR = mod_num(arrR);
		ll sL = (modL*(modL-1))%M;
		   sL = (sL*(modexp(2,M-2,M)))%M;
		   sL = sL - remove(arrL)%M;
		ll sR = (modR*(modR+1))%M;
		   sR =(sR*(modexp(2,M-2, M)))%M;
		   sR = sR - remove(arrR)%M;

		   

	}
	
	return 0;
}
