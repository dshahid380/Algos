#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];


vector<int> howSum(int targetSum, vector<int> nums){
	vector<int> v;
	if(targetSum == 0)
		return v;
	for(int x : nums){
		int rem = targetSum - x;
		if(rem >= 0){
			v = howSum(rem, nums);
			if(v.size() > 0 && v[0] == -1){
				continue;
			}
			v.push_back(x);
			return v;
		}
	}
	return {-1};	
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
    	int targetSum, n;
    	cin >> targetSum >> n;
    	vector<int> nums(n);
    	for(int i = 0; i < n; i++)
    		cin >> nums[i];
    	memset(dp, -1, sizeof dp);
    	vector<int> v = howSum(targetSum, nums);
    	for(int x : v) cout << x << " ";

    }
	return 0;
}