#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
		return true;

	return false;
}

int precedence(char ch){
	if(ch == '^')
		return 3;
	else if(ch == '/' || ch == '*')
		return 2;
	else if(ch == '+' || ch == '-')
		return 1;
	return 0;
}

string getPostFlix(string& s){
	stack<char> st;
	string res = "";

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(')
			st.push(s[i]);

		else if(s[i] == ')'){
			while(!st.empty() && st.top() != '('){
				res += st.top();
				st.pop();
			}
			st.pop();
		}else if(isOperand(s[i])){
			res += s[i];
		}else{
			while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}

	while(!st.empty()){
		res += st.top();
		st.pop();
	}

	return res;
		
}

int main(){

	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		cout << getPostFlix(s) << endl;
		// cout << s << endl;
	}
}

/*
((a + b) + c)
ab+c+
*/