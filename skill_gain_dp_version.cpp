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
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
//#define n 5
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
 int n;
 int t[1001]; //queen[i] -> where is my queen in row i.
 int s[1001];
 int x,k;
 


int dp[101][101][101]; 

 
int rec(int level,int time_taken, int item_taken){ 
	// max skill i can make from [level...n-1]..if [0..level-1 is decided]... and parameters mean from [0..level-1]
	// level -> current item in [0..n-1]
	
	
	// pruning
	
	
	//base case
	
	if(level==n){
		return 0;
	}
	
	//cache check
	
	if(dp[level][time_taken][item_taken]!=-1){
		return dp[level][time_taken][item_taken];
	}
	//compute or transition
	int ans = rec(level+1,time_taken,item_taken);
	if(time_taken+t[level]<=x && item_taken +1 <=k){
		ans = max(ans,s[level]+rec(level+1,time_taken+t[level],item_taken+1));
	}
	// save and return 
	return ans;
}



void solve(){
	int n;
	cin>>n;
	for(int i =0; i<n; i++){
		cin>>t[i]>>s[i];
	}
	cin>>x>>k;
	memset(dp,-1,sizeof(dp));
	cout<<rec(0)<<endl;
	
	
  }
	

signed main() {
	fio;
    // int t=1;
    // cin>>t;
// while(t--){?
	solve();
// }   
}
