#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int r, c, cnt=0, ip;
		vvi M;
		vi B;
		cin >> r >> c;
		
		for(int i = 0; i < r; i++)
			{
			for(int j = 0; j < c; j++) 
				{
				cin >> ip;
				B.push_back(ip);
		    }
		    M.push_back(B);
		}
	
		
		for( int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if((i==0 && j==0) || (i==r-1 && j==0) || (i==r-1 && j==c-1 ) || (i==0 && j==c-1)){
					if(M[i][j]>1)
					   cnt++;
				}
				else if(i==0 || j==0 || i==r-1 || j==c-1){
					if(M[i][j]>3)
					   cnt++;
				}
				else{
					if(M[i][j]>4)
					  cnt++;
				}
			}
		}
		
		if(cnt==0) cout<<"Stable"<<endl;
		else cout<<"Unstable"<<endl;
		
	}
	return 0;
}
