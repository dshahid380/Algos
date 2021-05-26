#include<bits/stdc++.h>
using namespace std;

int dp[1000];

bool canSum(int targetSum, vector<int> numbers){
	if(dp[targetSum] != -1) {
		return dp[targetSum] == 1 ? true : false;
	}

	if(targetSum == 0) 
		return true;

	if(targetSum < 0)
		return false;

	for(int i = 0; i < numbers.size(); i++) {
		if(canSum(targetSum - numbers[i], numbers)) {
			dp[targetSum] = 1;
			return true;
		}
	}
	dp[targetSum] = 0;
	return false;
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
    	cout << canSum(targetSum, nums)<< endl;

    }
	return 0;
}