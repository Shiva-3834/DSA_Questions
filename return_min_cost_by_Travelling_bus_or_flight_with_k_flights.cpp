#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;
const int INF = 1e9;

int n, k, m;
int a[100010], b[100010];
int dp[100010][1001];

int rec(int level, int num)
{
    // recursive version

    // prunning
    if (level < 1)
    {
        return INF;
    }

    // base case
    if (level == 1 && num == 0)
    {
        return 0;
    }
    else if (level == 1)
    {
        return INF;
    }
    // cache check
    if (dp[num][level] != -1)
    {
        return dp[num][level];
    }

    // transition
    int ans = 0;
    ans = rec(level - 1, num) + b[level - 1]; // bus
    if (num > 0)
    {
        for (int j = 1; j <= k; j++)
        {
            ans = min(ans, rec(level - j, num - 1) + a[level - j] + a[level]);
        }
    }

    // save and return
    return dp[num][level] = ans;
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

    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i = n - 1; i++)
    {
        cin >> b[i];
    }
}

void solve2()
{

    // if atmost k flights
    input();
    monotone_deque dq;
    for (int j = 0; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            //(i,j) the city at which you are at and the np.of flights
            if (i == 1 && j == 0)
            {
                dp[j][i] = 0;
            }
            else if (i == 1)
            {
                dp[j][i] = INF;
            }
            else
            {

               

                dp[j][i] = dp[j][i - 1] + b[i - 1]; // bus
          
            
                if (j > 0)
                {
                     dq.insert(dp[j-1][i-1] + a[i - 1]);
                if (i - k - 1 >= 1)
                    dq.remove(dp[j - 1][i-k-1]);

                dp[j][i] = min(dp[j][i], dq.getmin() + a[i])
                }
            
            }

            
        }
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