#include <bits/stdc++.h>
#define int long long
using namespace std;

string arr[505];
int n, m;
const int mod = 1e9 + 7;

int dp[505][505][505];

int rec(int x1, int y1, int x2, int y2)
{
    // pruning
    if (x1 > x2 || y1 > y2)
        return 0;
    if (arr[x1][y1] != arr[x2][y2])
        return 0;

    // base case
    int pathlen = (x1 - 1 + y1 - 1) + (n - x2 + m - y2); // this is the complete path length

    if (pathlen == (n - 1) + (m - 1)){
    // even number of moves , odd length palindrome
       
            return 1;

    } else if (pathlen + 1 == (n - 1) + (m - 1))
        { 
            // if they are side by side and the char are equal
            // odd number of moves , even length palindrome

            return 1;
        }
    

    if (dp[x1][y1][x2] != -1)
    {
        return dp[x1][y1][x2];
    }

    // recursion

    int ans = 0;
    ans += rec(x1 + 1, y1, x2 - 1, y2) % mod;
    ans += rec(x1 + 1, y1, x2, y2 - 1) % mod;
    ans %= mod;
    ans += rec(x1, y1 + 1, x2 - 1, y2) % mod;
    ans %= mod;
    ans += rec(x1, y1 + 1, x2, y2 - 1) % mod;
    ans %= mod;
    // save and return
    dp[x1][y1][x2] = ans % mod;
    return ans;
}

void solve()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        // for (int j = 1; j <= m; j++)
        // {
        //     cin >> arr[i][j];
        // }
        cin >> arr[i];
        arr[i] ="0"+arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(1, 1, n, m) % mod << endl;
}

signed main()
{

    // int t=1;
    // // cin >> t;
    // while (t--)
    // {
        solve();
    // }
}