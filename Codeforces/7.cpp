#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg
typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;
const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 100007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 2;
const int CNT = 800;
Int F1[MAX];
Int F2[MAX];
Int dp[2][MAX];
Int sum[MAX];

Int bpow(Int a, int k)
{
    Int res = 1;
    while (k)
    {
        if (k & 1)
        {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        k /= 2;
    }
    return res;
}
Int C(int k)
{
    return F1[k] * bpow(F2[k] , MOD - 2) % MOD;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif
    
    int MAXK = 100000;
    
    dp[0][0] = 1;
    sum[0] = 1;
    
    int prev = 0;
    int next = 1;
    
    FOR(i,1,400)
    {
        FILL(dp[next] , 0);
        FOR(j,i,MAXK + 1)
        {
            dp[next][j] = (dp[next][j - i] + dp[prev][j - i]) % MOD;
            if (i % 2 == 0)
            {
                sum[j] += dp[next][j];
                sum[j] %= MOD;
            }
            else
            {
                sum[j] -= dp[next][j];
                if (sum[j] < 0) sum[j] += MOD;
            }
        }
        swap(prev , next);
    }
    
    int t;
    cin >> t;
    FOR(tt,0,t)
    {
        int n , k;
        cin >> n >> k;
        
        F1[0] = 1;
        F2[0] = 1;
        FOR(i,1,k + 1)
        {
            F1[i] = F1[i - 1] * (n + i - 1) % MOD;
            F2[i] = F2[i - 1] * i % MOD;
        }
        
        Int res = 0;
        FOR(i,0,k + 1)
        {
            res += (sum[i] *)% MOD;
            res %= MOD;
        }
        
        cout << res << endl;
        
    }
    
    return 0;
}