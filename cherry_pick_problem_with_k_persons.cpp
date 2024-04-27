#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int n, m, k;
int arr[50][50];

map<pair<vector<int>, int>, int> dp;

bool check(int x, int y)
{
	if (x >= n || y >= m)
		return 0;
	return 1;
}

int rec(vector<int> rowVal, int c0)
{ // r1+c1==r2+c2
	int totRow = 0;
	int totCol = 0;
	vector<int> colVal;
	for (int i = 0; i < k; i++)
	{
		colVal.push_back(rowVal[0] + c0 - rowVal[i]);
		if (!check(rowVal[i], colVal[i]))
		{
			return -1e9;
		}

		totRow += rowVal[i];
		totCol += colVal[i];
	}

	// base case
	if (totRow == k * (n - 1) && totCol == k * (m - 1))
	{
		return arr[n - 1][m - 1];
	}
	// cache check
	if (dp.find(make_pair(rowVal, c0)) != dp.end())
	{
		return dp[make_pair(rowVal, c0)];
	}

	// transition
	int ans = 0;
	int temp = 0;
	set<pair<int, int>> st;
	for (int i = 0; i < k; i++)
	{
		st.insert({rowVal[i], colVal[i]});
	}
	for (auto v : st)
	{
		temp += arr[v.first][v.second];
	}
	// there will be 2^k different transitions to traverse efficiently will use bitmask
	for (int mask = 0; mask < (1 << k); mask++)
	{
		vector<int> rNew = rowVal;
		int c0new = c0;
		for (int i = 0; i < k; i++)
		{
			if (mask & (1 << i))
			{
				rNew[i]++;
			}
			else
			{
				if (i == 0)
					c0new++; // column only increases for the first column
			}
		}
		ans = max(ans, temp + rec(rNew, c0new));
	}
	return dp[make_pair(rowVal, c0)] = ans;
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			// dp[i][j] = -1e18
		}
	}

	// memset(dp, -1e18, sizeof(dp)); // use loops not memset
	cout << rec(0, 0, 0, 0);
}

signed main()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
}




