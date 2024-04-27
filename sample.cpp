#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> arr[51];

struct max_sum_val
{

    int best;
    int prebest;
    int suffbest;
    int tot;

    void build(vector<int> arr)
    {
        int n = arr.size();

        tot = 0;
        for (int i = 0; i < n; i++)
        {
            tot += arr[i];
        }

        prebest = arr[0];
        int prefix_sum = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix_sum += arr[i];
            prebest = max(prebest, prefix_sum);
        }

        suffbest = arr[n - 1];
        int suffix_sum = arr[n - 1];
        for (int i = n-2; i>=0; i--)
        {
            suffix_sum += arr[i];
            suffbest = max(suffbest, suffix_sum);
        }
        best = tot;
        int lastbest = 0;

        for (int i = 0; i < n; i++)
        {
            lastbest = max(lastbest + arr[i], arr[i]); // kadanes algo t.c ->O(n), s.c->O(1)
            best = max(best, lastbest);
        }
    }
};

max_sum_val converted[51];
max_sum_val merge_arrays(max_sum_val a, max_sum_val b)
{

    max_sum_val ans;
    ans.best = max({a.best, b.best, a.suffbest + b.prebest});
    ans.prebest = max(a.prebest, a.tot + b.prebest);
    ans.suffbest = max(b.suffbest, b.tot + a.suffbest);
    ans.tot = a.tot + b.tot;
    return ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        arr[i].clear();
        for (int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
        converted[i].build(arr[i]);
    }
    int final_pos[m];
    for (int j = 0; j < m; j++)
    {
        cin >> final_pos[j];
    }
    max_sum_val final_ans = converted[final_pos[0]];
    for (int j = 1; j < m; j++)
    {
        final_ans = merge_arrays(final_ans, converted[final_pos[j]]);
    }
    cout << final_ans.best << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
