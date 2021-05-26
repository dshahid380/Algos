#include<bits/stdc++.h>
using namespace std;

vector<int> bestSum(int targetSum, vector<int> nums){
	vector<int> bestSumArray = {-1};
	if(targetSum == 0)
		return {};

	for(int x : nums){
		int rem = targetSum - x;
		if(rem >=0){
			vector<int> v = bestSum(rem, nums);
			if(v.size() > 0 && v[0] == -1)
				continue;

			v.push_back(x);
			if(bestSumArray[0] == -1 || bestSumArray.size() > v.size()){
				bestSumArray = v;
			}
		}	

	}

	return bestSumArray;
}

int main(){

	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);

	int t;
	cin >> t;
	while(t--){
		int targetSum, n;
		cin >> targetSum >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		vector<int> v = bestSum(targetSum, nums);
		for(int x : v){
			cout << x << " ";
		}
	}
	return 0;
}