#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
		return true;

	return false;
}


string getInfix(string & s){
	stack<string> st;

	for(int i = 0; i < s.size(); i++){
		if(isOperand(s[i])){
			string operand = string(1, s[i]);
			st.push(operand);
		}else{
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();
			string res = '(' + op2 + s[i] + op1 + ')';
			st.push(res);
		}
	}
	return st.top();
}

int main(){
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >>  s;
		cout << getInfix(s) << endl;
	}
	return 0;
}

/*
ab+c+ -> ((a+b)+c)
abcd^e-fgh*+^*+i- -> a+b*(c^d-e)^(f+g*h)-i
*/