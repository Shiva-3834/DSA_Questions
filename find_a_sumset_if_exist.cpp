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
 int t;
 int x[101];
 

int dp[105][10100];

 
int rec(int level,int taken){ 

//pruning
if(taken>t)return 0;
//basecase
if(level==n+1){
	if(t==taken){ // if we at the target solution then we are the correct place 
		return 1;
		
	}else{
		return 0;
	}
}
// cache check
if(dp[level][taken]!=-1){
	return dp[level][taken];
}


//compute
int ans = 0;
if(rec(level+1,taken)==1){ // if you dont take it
	ans =1;
}else if(rec(level+1, taken+x[level])){ //if you take it 
	ans =1;
}

// save and return 
return dp[level][taken]=ans;

}



void solve(){
	int n;
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>x[i];
	}
	cin>>t;
	memset(dp,-1,sizeof(dp));
	cout<<rec(1,0);
  }
	

signed main() {
	fio;
    // int t=1;
    // cin>>t;
// while(t--){?
	solve();
// }   
}
