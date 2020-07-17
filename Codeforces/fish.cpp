#include<bits/stdc++.h>
using namespace std;


int  main(){
	freopen("fish.in", "w", stdout);
	srand(time(0));
	int t=5000;
	cout<<t<<endl;
	while(t--)
	{   int n = 50, q = 100;
		cout<<n<<" "<<q<<endl;
		for(int i = 0; i < n; ++i)
	           cout<<rand()%10 + 1<<" "; cout<<endl;
	       for(int i = 0; i < n; ++i)
	           cout<<rand()%10 + 1<<" "; cout<<endl;
	       for(int i = 0; i < q; ++i) {
	           cout<<rand()%2 + 1<<" "<<rand()%n + 1<<" "<<rand()%n+1<<endl;
	       }
	 }
	

}

