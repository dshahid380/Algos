#include<bits/stdc++.h>
using namespace std;
int MAX = (int)1e6;
vector<bool> prime(MAX,true);

int checkMax(string str, int l, int r) {
	 while(l>=0 && r<str.length() && str[l]==str[r]) {
	 	  l--;
	 	  r++;
	 }
	 string s = str.substr(l+1, r-l-1);
	 return s.length();
}

int maxLength(string str) {
	 int max1=0, max2=0,curr=0;
	 for(int i=0; i<str.length(); ++i) {
	 	  curr = checkMax(str, i, i);
	 	  max1 = max(max1, curr);
	 	  curr = checkMax(str, i, i+1);
	 	  max2 = max(max2, curr);
	 }
	 return max(max1,max2);
}

void prep() {
	 int i=2;
	 prime[0]=prime[1]=false;
	 while(i*i<=MAX) {
	 	  if(prime[i]) {
	 	  	  int j = i*i;
	 	  	  while(j<=MAX) {
	 	  	  	 prime[j] = false;
	 	  	  	 j+=i;
					}
			}
			i+=1;
	 } 
}

int main() {
	 prep();
	 int T;
	 cin>>T;
	 while(T--) {
	 	  string str;
	 	  cin>>str;
	 	  int len = maxLength(str);
	 	  if(prime[len])
	 	     cout<<"PRIME"<<endl;
	 	  else 
	 	     cout<<"NOT PRIME"<<endl;
	 }
	 return 0;
}
