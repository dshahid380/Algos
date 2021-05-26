int main(){
	int t;
	cin>>t;
	for(int tt = 0; tt < t; tt++){
		int stn;
		cin>>stn;
		int n=stn+1;
		int state[n+1];
		for(int i=0;i<=n;i++)
		    if(i == 0){
		        state[0]=1;
		    }else if( i < 3){
		        state[i] = i;
		    }
		    else{
			    state[i]=state[i-1]+state[i-2]+state[i-3];
		    }

		cout<<state[n]<<endl;

	}
}