#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int n, k;
string comp;
int arr[100100];
map<char, int> mp;
map<int, char> rmp;

// P=0, H=1, S=2
// (0,1), (1,2), (2,0) //this all true rest all false

int result(int mymove, int compmove)
{
	return compmove == (mymove + 1) % 3;
}

int dp[100100][3][101];
vector<int> back[100100][3][101];

int rec(int level, int last, int ch_left)
{
	// pruning
	if (ch_left < 0)
		return -1e9;
	// base case
	if (level == n)
	{
		return 0;
	}

	// cache check

	if (dp[level][last][ch_left] != -1)
		return dp[level][last][ch_left];

	// transition
	int ans = 0;
	back[level][last][ch_left] = {};

	for (int x = 0; x < 3; x++)
	{
		int temp = result(x, arr[level]) + rec(level + 1, x, ch_left - ((x == last) ? 0 : 1));
		if (temp > ans)
		{
			back[level][last][ch_left] = {x};
		}
		else if (temp == ans)
		{
			back[level][last][ch_left].push_back(x);
		}
	}
	return dp[level][last][ch_left] = ans;
}
vector<string> all_sol;
string cur_sol;

string final_ans;
void generate(int level, int last, int ch_left)
{
	if (level == n)
		all_sol.push_back(cur_sol);
		return;

	for (auto x : back[level][last][ch_left])
	{
		cur_sol += rmp[x];
		generate(level + 1, x, ch_left - ((x == last) ? 0 : 1));
		cur_sol.pop_back();
	}
}
void solve()
{
	mp['p'] = 0;
	mp['H'] = 1;
	mp['S'] = 2;
	rmp[0] = 'p';
	rmp[1] = 'H';
	rmp[2] = 'S';

	cin >>n >> k;
	cin >> comp;
	for (int i = 0; i < n; i++)
	{
		arr[i] = mp[comp[i]];
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
			for (int x = 0; x <= k; x++)
			{
				dp[i][j][x] = -1;
			}
	}

	// pair<int, int> ans = max({MP(rec(0, 0, k), 0),MP( rec(0, 1, k), 1), MP(rec(0, 2, k), 2)});

	// cout << ans.first << endl;
	// generate(0, ans.second, k);
	// cout << final_ans << endl;

	int ans = 0;
	int best = 0;
	for (int i = 0; i < 3; i++)
	{
		int temp = rec(0, i, k);
		if (temp > ans)
		{
			ans = temp;
			best = i;
		}
	}
	cout << ans << endl;
	generate(0, best, k);
	cout << final_ans << endl;
}

signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}