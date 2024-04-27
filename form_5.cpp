#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100100];
int rec(int x)
{
	// base case
	if (x == 0)
	{
		return 0;
	}
	// cache check
	if (dp[x] != -1)
	{
		return dp[x];
	}

	// transition
	int ans = 0;
	// we have to check all the states
	for (int m = 0; (1 << m) <= x; m++)
	{ // 2^m = 1<<m
		if (rec(x - (1 << m)) == 0)
		{ // if anyone of the state im reaching is loosing then my current state is winning
			ans = 1;
			break;
		}
	}

	// save and return
	return dp[x] = ans;
}
void solve()
{
	int n;
	cin >> n;
	// memset(dp,-1,sizeof(dp));
	// cout<<rec(n-1)<<endl;
	// //  for(int i=0; i<=10; i++){
	// //  	// cout<<i<<" "<<rec(i)<<endl;
	// // 	cout<<rec(i)<<endl;
	// //  }
	
	if (n % 3)
	{
		cout << "Vivek" << endl;
	}
	else
	{
		cout << "Abhishek" << endl;
	}
}

signed main()
{
	int t ;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}
