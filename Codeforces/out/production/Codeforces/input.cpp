#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("1.in","w", stdout);
	int t = 100;
	cout<<t<<endl;
	while(t--){
		int a=rand()%200+1, b=rand()%200+1, q=rand()%30;
		cout<<a<<" "<<b<<" "<<q<<endl;
		for(int i=0; i<q; i++){
			int l = rand()%300+1, r = l+rand()%300+1;
			cout<<l<<" "<<r<<endl;
		}

	}
}