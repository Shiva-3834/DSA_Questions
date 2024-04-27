#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9 + 7;

int n;
char arr[1001][1001];
int dp[1001][1001];

int rec(int r, int c){
    // pruning
    if(r < 0 || c < 0 || arr[r][c] == '*'){
        // not possible
        return 0;
    }

    // base case
    if(r == 0 && c == 0){
        return 1;
    }

    // save and check
    if(dp[r][c] != -1){
        return dp[r][c];
    }

    // compute
    int ways = 0;
    if(r != 0){
        ways = (ways + rec(r - 1, c)) % MOD;
    }
    if(c != 0){
        ways = (ways + rec(r, c - 1)) % MOD;
    }

    // save and return
    return dp[r][c] = ways;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << rec(n-1, n-1) << endl;
}

int main(){
    fio;
    solve();
    return 0;
}
