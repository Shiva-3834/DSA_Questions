#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;
const int INF = 1e9;

int n, k, m;
int a[100010], b[100010];
int dp[100010][1001];

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
                dp[j & 1][i] = 0;
            }
            else if (i == 1)
            {
                dp[j & 1][i] = INF;
            }
            else
            {

                dp[j & 1][i] = dp[j & 1][i - 1] + b[i - 1]; // bus

                if (j > 0)
                {
                    dq.insert(dp[(j - 1) & 1][i - 1] + a[i - 1]);
                    if (i - k - 1 >= 1)
                        dq.remove(dp[(j - 1) & 1][i - k - 1]);

                    dp[j & 1][i] = min(dp[j & 1][i], dq.getmin() + a[i])
                }
            }
        }
    }
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