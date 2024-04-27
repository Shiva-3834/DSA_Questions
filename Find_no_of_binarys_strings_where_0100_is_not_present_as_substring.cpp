#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

#define fio                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int n;
string t = "0100";

int dp[100100][5];
// vector<vector<int>> dp;
int rec(int level, int match)
{
    // pruning
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
    // transition
    int ans = 0;
    if (match == 0)

    {
        ans = ans % mod;
        ans = ((rec(level + 1, 0) % mod) + (rec(level + 1, 1)) % mod) % mod; //(level, state)
    }
    else if (match == 1) // if you are at state 1
    {
        ans = ans % mod; // when you are at state 1, with 0 you go state 2
                         // with 1 you go to state 1
        ans = ((rec(level + 1, 1)) % mod + (rec(level + 1, 2)) % mod) % mod;
    }
    else if (match == 2)
    {
        ans = ans % mod;
        ans = (rec(level + 1, 0) % mod + rec(level + 1, 3) % mod) % mod;
    }
    else if (match == 3)
    {
        ans = ans % mod;
        ans = (rec(level + 1, 2) % mod + rec(level + 1, 4) % mod) % mod;
    }
    // save and return
    return dp[level][match] = ans % mod;
}

void solve()
{
    cin >> n;
    // dp.assign(n, vector<int>(n, -1));
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) % mod << endl;
}

signed main()
{
    fio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}