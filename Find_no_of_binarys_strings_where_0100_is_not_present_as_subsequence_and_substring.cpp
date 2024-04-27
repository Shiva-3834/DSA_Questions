#include <bits/stdc++.h>
using namespace std;
const int mod =1e9+7;

#define fio                       \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0)

int n;
string t = "0100";

int dp[100100][5];
int rec(int level, int match)
{
    // prunning
    if (match == 4)
    {
        return 0;
    }
    // base case
    if (level == n)
    {
        return 1;
    }
    // cache check
    if (dp[level][match] != -1)
    {
        return dp[level][match];
    }
    // compute
    int ans = ((rec(level + 1, match + 1)%mod) +( rec(level + 1, match)%mod))%mod;
    // save and return
    return dp[level][match] =ans;
}

void solve()
{
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << rec(0, 0)%mod << endl;
}

int main()
{
    fio;
    int t;
    cin>>t;
    while(t--){
    solve();
}
}