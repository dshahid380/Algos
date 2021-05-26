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


bool canCanstruct(string target, vector<string> wordBank){
	if(target == "")
		return true;

	for(string word : wordBank){
		if(isPrefix(target, word)){
			string suffix = sliceWord(target, word);
			if(canCanstruct(suffix, wordBank))
				return true;
		}
	}
	return false;
}

int main(){

	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);

	int t;
	cin >> t;
	while(t--){
		string target;
		int n;
		cin >> target;
		cin >> n;
		vector<string> wordBank(n);
		for(int i = 0; i < n; i++){
			cin >> wordBank[i];
		}
		cout << canCanstruct(target, wordBank);

	}
	return 0;
}