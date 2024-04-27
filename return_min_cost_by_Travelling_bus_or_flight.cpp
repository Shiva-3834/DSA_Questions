#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;
const int INF = 1e9;

int n, k;
int a[100010], b[100010];
int dp[100010];

int rec(int level)
{
    // prunning
    if (level < 1)
    {
        return INF;
    }

    // base case
    if (level == 1)
    {
        return 0;
    }
    // cache check
    if (dp[level] != -1)
    {
        return dp[level];
    }

    // transition
    int ans = 0;
    ans = rec(level - 1) + b[level - 1]; // bus
    for (int j = 1; j <= k; j++)
    {
        ans = min(ans, rec(level - j) + a[level - j] + a[level]);
    }
    // save and return
    return dp[level] = ans;
}

void solve()
{
    cin >> n>>k;
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
    }
    cout << rec(n-1) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        solve();
    }
}