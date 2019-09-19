#include<bits/stdc++.h>
using namespace std;
vector<int> z_function(string s) {
	int n = (int) s.size();
	vector<int> z(n,0);
	int x=0, y=0;
	for(int i=1;i<n;i++){
		z[i] = max(0,min(z[i-x],y-i+1));
		while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
			x=i; y=i+z[i]; z[i]++;
		}
		
	}
	return z;
}

int main() {
	string s;
	getline(cin, s);
	//cout<<s;
	int n = s.size();
	vector<int> Z = z_function(s);  
	/* for(int i=0; i<n; i++)
	   cout<<Z[i]<<" ";
	cout<<endl; */
	unordered_map<int, int> freq;
	for(int i=0; i<n; i++){
		if(Z[i]!=0)
		   freq[Z[i]]++;
	} 
	//cout<<"Init map"<<endl;
	int ans=-1; 
	int maxx = *max_element(Z.begin(), Z.end());
	
	for(int i=n-1; i>=0; i--){
		 if(Z[i]!=0){
		 	 if(n-i-Z[i]==0 and freq.find(Z[i])!=freq.end()) {
		 	 	   if(freq[Z[i]]>1)
		 	        ans = i;
		 	     else {
		 	     	 if(Z[i]<maxx) 
							  ans = i; 
					}
				}
		 	     
		 }
	}
	//cout<<"ans;;;"<<endl;
	if(ans==-1)
	   cout<<"Just a legend"<<endl;
	else{
		for(int i=ans; i<n; i++)
		   cout<<s[i];
		cout<<endl;
	}  
	return 0;
}
