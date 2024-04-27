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
    // recursive version

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

struct monotone_deque
{
    deque<int> dq;
    void insert(int x)
    {
        while (!dq.empty() && dq.back() > x)
        {
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x)
    {
        if (!dq.empty())
        {
            if (dq.front() = x)
                dq.pop_back();
        }
    }
    int getmin(int x)
    {
        if (!dq.empty())
        {
            return dq.front();
        }
        else
        {
            return 0;
        }
    }
};

void input()
{

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i = n - 1; i++)
    {
        cin >> b[i];
    }
}

void solve()
{
    // iterative version
    input();
    dp[1] = 0;

    monotone_deque dq;

    for (int level = 2; level <= n; level++)
    {
        dp[level] = dp[level - 1] + b[level - 1];
        dq.insert(dp[level - 1] + a[level - 1]);
        if (level - k - 1 >= 1)
            dq.remove(dp[level - 1] + a[level - 1]);

        dp[level] = min(dp[level], dq.getmin() + a[level]);
    }
    cout << dp[n] << endl;
    // TC-> O(n)
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}