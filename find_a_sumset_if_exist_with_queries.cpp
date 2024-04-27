#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

#define F first 
#define S second 
#define pb push_back 
#define endl "\n"
#define forn(i, n) for (int i = 0; i < int(n); i++)

int n;
int t;
int x[101];
int dp[105][10100];

int rec(int level, int left) {
    // Pruning
    if (left < 0) return 0;

    // Base case
    if (level == n+1 ) {
        return (left == 0) ? 1 : 0;
    }

    // Cache check
    if (dp[level][left] != -1) {
        return dp[level][left];
    }

    // Compute
    int ans = 0;
    if (rec(level + 1, left) == 1) {
        ans = 1;
    } else if (rec(level + 1, left - x[level])) {
        ans = 1;
    }

    // Save and return
    return dp[level][left] = ans;
}

void printset(int level, int left) {
    cout << "printer:" << level << " " << left << endl;

    // Base case
    if (level == n+1 ) {
        return;
    }

    // Find the correct transition
    if (rec(level + 1, left) == 1) { // Don't take
        printset(level + 1, left);
    } else if (rec(level + 1, left - x[level]) == 1) { // Take
        cout << x[level] << " ";
        printset(level + 1, left - x[level]);
    }
}

void solve() {
    cin >> n;
    for (int i =0 ; i < n; i++) {
        cin >> x[i];
    }

    // we are here caching it only once, across all the queries we are using same array
    memset(dp, -1, sizeof(dp)); // O(no.of state)+O(DP)

    int q;
    cin >> q;
    while (q--) { //O(q)
        cin >> t;
        if (rec(0, t)) {
            printset(1, t);
            cout << endl;
        } else {
            cout << "No solution" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
