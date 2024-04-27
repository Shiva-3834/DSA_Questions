#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";
#define mod 1e9 + 7
#define int long long 

vector<int> arr;
vector<int> cnt;
vector<int> len;
int n;
void solve(){
    cin >> n;
    cnt.assign(n + 1, 1);
    len.assign(n + 1, 1);
    arr.assign(n + 1, 1);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int mxlen = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j]){
                if ((len[j] + 1) > len[i]){
                    len[i] = 1 + len[j];
                    cnt[i] = cnt[j];
                }
                else if ((len[j] + 1) == len[i]){
                    cnt[i] += cnt[j];
                }
            }
        }
        mxlen = max(mxlen, len[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (len[i] == mxlen){
            ans += cnt[i];
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}