#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fio                       \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0)

const int inf = 1e9;
//palindrome
string s;

int n;
vector<vector<int>> dp;

int solve(int l, int r)
{
	// base case for transition 1
	// if (l == r)
	// { // when l and r are point on same element
	// 	return 1;
	// }

	// base case for transition 2
	if (l > r)
	{
		return 0;
	}


	// cache check
	if (dp[l][r] != -1)
	{
		return dp[l][r];
	}
	/*
	// transition 1
	if (s[l] == s[r])
	{

		dp[l][r] = solve(l + r, r - 1) + 2;
	}

	else
	{
		dp[l][r] = max(solve(l + r, r), solve(l, r - 1));
	}
*/
	// transition 2
	
	if (s[l] == s[r])
	{
		if (l == r) //if l and r are pointing to same element
		{
			dp[l][r] = 1;
		}
	
	else
	{
		dp[l][r] = solve(l + r, r - 1) + 2;
	}
	}
	else
	{
		dp[l][r] = max(solve(l + r, r), solve(l, r - 1));
	}
	

	return dp[l][r];
}

int main()
{
	fio;
	
	return 0;
}