#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cassert>
#include <climits>
#include <functional>
#include <bitset>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define print(x) cout<<#x<<" is "<<x<<endl;
#define inf 2000000000
#define eps 1e-8
#define fill(x,y) memset(x,y,sizeof(x))

using namespace std;

#define maxn 1000

char s[maxn], temp[maxn];//the arrangement
int k;//the allowed number of colors <=10
int l;//length of s
const string no = "NO";

//fixes the char at mid position
void fix(int left, int mid, int right) {
    if(s[mid]!='?')
	return;
    for(char cur='0'; cur <='2'; cur++)
	if(s[left]!=cur && s[right]!=cur) {
	    s[mid] = cur;
	    break;
	}
}

string solve() {
    //if length is 1 return the obvious.
    if(l==1) {
	if(s[0]=='?')
	    return "0";
	else if(s[0]-'0' < k)
	    return s;
	return no;
    }

    //only one color allowed so possible iff l==1 && (color==0 || color=='?').
    if(k==1) {
	if(l==1 && (s[0]=='0' || s[0]=='?'))
		return "0";
	return no;
    }
    else if(k==2) {
	//2 colors only allowed are 010101....01 || 101010...10
	if(l&1)
	    return no;
	bool pos = true;
	strcpy(temp, s);
	for(int i=0; i<l;i++) {
	    if(s[i]=='?')
		s[i] = '0'+i%2;
	    else if(s[i]!=('0'+i%2)) {
		    pos = false;
		    break;
	    }
	}
	if(pos)
	    return s;
	pos = true;
	strcpy(s,temp);
	for(int i=0; i<l;i++) {
	    if(s[i]=='?')
		s[i] = '0'+1-i%2;
	    else if(s[i]!=('0'+1-i%2)) {
		pos = false;
		break;
	    }
	}
	if(pos)
	    return s;
	return no;
    }
    /*  k >=3 greedy approach can be followed.
	the only not possible cases are when two
	adjacent are already same circularly. */
    for(int i=1;i<l;i++) {
	if(s[i]==s[i-1] && s[i]!='?')
	    return no;
    }
    if(s[l-1]==s[0] && s[0]!='?')
	return no;

    fix(l-1,0,1);
    /*  now that first element is fixed and every circular
	array can be 3 colored. */
    for(int i=1;i<l-1;i++)
	fix(i-1,i,i+1);
    fix(0,l-1,l-2);
    return s;
}

int main() {
    int nt; //number of cases.
    scanf("%d",&nt);
    assert(nt<=1000);
    while(nt--) {
	scanf("%d%s",&k,s);
	l = strlen(s);
	assert(k>=1 && l<=100 && k<=10);
	string ret = solve();
	cout<<ret<<endl;
    }
    return 0;
}
