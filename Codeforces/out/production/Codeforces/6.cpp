#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0, h = 0, l = 0;
    for(char c : s){
        if(c == 'L')
            l++;
    }
    for(char c : s){
        if(c == 'S')
            ans += (h*l);
        else if(c == 'H')
            h++;
        else
            l--;
    }
    cout << ans << endl;
}
