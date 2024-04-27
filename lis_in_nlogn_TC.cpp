#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
// T.c => O(n*logn)
int n, m;

int dp[404][404][404];

void solve()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> lis;
    for (int i = 0; i < n; i++)
    {
        if (lis.empty() || lis.back() < arr[i])
        {
            lis.push_back(arr[i]);
        }
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i]; // replacing the element
        }

        // printing the length of LIS but its not the actual LIS

        cout << i << " : ";
        for (auto v : lis)
        {
            cout << v << ", ";
        }
        cout << endl;
    }
    cout << lis.size() << endl;

    // T.C => O(n*logn)
    //  the above code only gives the length of the LIS but it wont give actual LIS
}

/*
10
1 5 7 10 9 6 7 9 2 3

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}