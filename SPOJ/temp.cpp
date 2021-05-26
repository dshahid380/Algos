#include<bits/stdc++.h>
using namespace std;

vector<int> numToVec(int n){
    vector<int> v;
    while(n!=0){
        v.push_back(n%10);
        n /= 10;
    }
    reverse(v.begin(),v.end());
    return v;
}

void print(vector<int> v){
    int f = 0;
    for(int i=0; i<600; ++i){
        if(v[i]!=0 && f==0){
            f = 1;
        }
        if(f==1)
            cout<<v[i];
    }
    cout<<endl;
}

void multiply(vector<int> &a, vector<int> &b){
    int end = 0;
    vector<int> ans(600,0);
    for(int i=b.size()-1; i>=0; i--){
        int carry = 0;
        vector<int> buffer(600,0);
        for(int j=599; j>=0; j--){
            int mul = b[i]*a[j] + carry;
            buffer[j] = mul%10;
            carry = mul/10;
        }
    
        carry = 0;
        for(int j=599; j>=end; --j){
            ans[j-end]+= buffer[j]+carry;
            carry = ans[j-end]/10;
            ans[j-end] = ans[j-end]%10;
        }
        end++;
    }
    for(int i=599; i>=0; --i)
        a[i] = ans[i];
}

void solve(int n){
    vector<int> a(600);
    a[599] = 1;
    for(int i=1; i<=n; ++i){
        vector<int> b = numToVec(i);
        multiply(a,b);
    }
    print(a);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.in","r", stdin);
        freopen("output.in","w",stdout);
    #endif

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        solve(n);
    }
    return 0;
}