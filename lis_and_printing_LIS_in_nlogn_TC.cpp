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
	int insertedat[n]; // it stores which element is inserted at where
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
			insertedat[i] = lis.size(); // i th element inserted at which length in lis array
										// for printing the LIS
		}
		else
		{
			auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
			*it = arr[i];
			insertedat[i] = it - lis.begin() + 1; // +1 gives the length, without +1 it gives the index where it get inserted
		}

		/*
		// printing the length of LIS but its not the actual LIS
				cout << i << " : ";
				for (auto v : lis)
				{
					cout << v << ", ";
				}
				cout << endl;
			}
			cout << lis.size() << endl;

			*/

		// printing the solution i.e actual LIS

		int curlen = lis.size();

		vector<int> final_lis;

		for (int i = n - 1; i >= 0; i--)
		{
			if (insertedat[i] == curlen) // at curlen which element is inserted
			{
				final_lis.push_back(arr[i]);
				curlen--;
			}
		}
		reverse(final_lis.begin(), final_lis.end());
		cout << "LIS: " << lis.size() << endl;
		for (auto v : final_lis)
		{
			cout << v << " ";
		}
	}
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