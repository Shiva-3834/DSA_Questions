#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n, m, x;
string a, b, c;
int dp[104][104][104];

int rec(int i, int j, int k)
{
    if (i >= n || j >= m || k >= x)
    {
        return 0;
    }

    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }

    int ans = 0;
    ans = max(ans, rec(i + 1, j, k));
    ans = max(ans, rec(i, j + 1, k));
    ans = max(ans, rec(i, j, k + 1));
    if (a[i] == b[j] && b[j] == c[k])
    {
        ans = max(ans, 1 + rec(i + 1, j + 1, k + 1));
    }
    return dp[i][j][k]=ans;
}

void solve(){
cin>>a>>b>>c;

    n = a.length();
    m = b.length();
    x = c.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<endl;

}

// #undef int 

signed main()
{
int t;
cin>>t;
while(t--){
    solve();
}
}