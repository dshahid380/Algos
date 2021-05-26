#include<bits/stdc++.h>
using namespace std;

bool isPrefix(string target, string word){
	if(target.size() < word.size())
		return false;
	for(int i = 0; i < word.size(); i++){
		if(target[i] != word[i])
			return false;
	}
	return true;
}

string sliceWord(string target, string word){
	
	string suffix = target.substr(word.size(), target.size() - word.size());
	return suffix;

}

vector<vector<string>> allConstruct(string target, vector<string> wordBank){
	if(target == ""){
		return {{}};
	}
	vector<vector<string>> allComb;
	for(string word : wordBank){
		if(isPrefix(target, word)){
			string suffix = sliceWord(target, word);
			vector<vector<string>> v = allConstruct(suffix, wordBank);
			for(int i = 0; i < v.size(); i++){
				v[i].push_back(word);

			}
			allComb.insert(allComb.end(), v.begin(), v.end());
		}
	}
	return allComb;
}

int main(){

	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);

	int t;
	cin >> t;

	while(t--){
		string target;
		cin >> target;
		int n;
		cin >> n;
		vector<string> wordBank(n);
		for(int i = 0; i < n; i++)
			cin >> wordBank[i];
		vector<vector<string>> ans = allConstruct(target, wordBank);
		for(auto v : ans){
			reverse(v.begin(), v.end());
			for(auto word : v){
				cout << word << " ";
			}
			cout << endl;
		}
		// vector<vector<int>> v;
		// vector<vector<int>> v1 = {{3,4}};
		// v.insert(v.end(), v1.begin(), v1.end());
		// cout << v[0][0] << ", " << v[0][1] << endl;
		// // cout << v[1][0] << ", " << v[1][1] << endl;
	}

	return 0;
}





