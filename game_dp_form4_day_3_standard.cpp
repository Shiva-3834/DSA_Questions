#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int arr[2021];
int dp[2021][2021];
bool done[2021][2021];

int rec(int l, int r)
{
    // base case
    if (l == r)
    { // if we reach single element
        return arr[l];
    }

    // cache check
    if (done[l][r])
    {
        return dp[l][r];
    }

    int ans = max(arr[l] - rec(l + 1, r), arr[r] - rec(l, r - 1));
    done[l][r] = 1;
    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            done[i][j] = 0;
        }
    }
    cout << rec(0, n - 1) << endl;
}

#undef int

int main()
{

    solve();
}