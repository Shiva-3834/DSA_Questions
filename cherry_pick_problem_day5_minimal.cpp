#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int n,m;
int arr[50][50];
int dp[50][50][50][50];

bool check(int x, int y){
	if(x>=n || y>=m )return 0;
	return 1;
}

int rec(int r1, int c1, int r2, int c2){
	
	if(!check(r1,c1) || !(check(r1,c1))){

		return -1e18;
	}
	//base case
 if(r1==n-1&&c1==m-1&&r2==n-1&&c2==m-1){
	return arr[r1][c1];
 }
//cache check
if(dp[r1][c1][r2][c2]!=-1e18){
return dp[r1][c1][r2][c2];
}
// transition
int ans = ((r1==r2 && c1 == c2)?arr[r1][c1]:arr[r1][c1]+arr[r2][c2]);

ans = ans+max({rec(r1+1,c1,r2+1,c2), rec(r1,c1+1,r2+1,c2),rec(r1+1,c1,r2,c2+1),rec(r1,c1+1,r2,c2+1)});
return dp[r1][c1][r2][c2] = ans;
}


void solve(){
	cin>>n>>m;
	for(int i=0; i<n;i++ ){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
			// dp[i][j] = -1e18
		}
	}

	memset(dp, -1e18, sizeof(dp)); //use loops not memset
	cout<<rec(0,0,0,0);
	
}

signed main(){
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}


/*optimized code*/
//dp state space reduction
//TC: O(n^3)

/*

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int n,m;
int arr[50][50];
int dp[50][50][50];

bool check(int x, int y){
	if(x>=n || y>=m )return 0;
	return 1;
}

int rec(int r1, int c1, int r2){ // r1+c1==r2+c2
	int c2 = r1+c1-r2;
	if(!check(r1,c1) || !(check(r1,c1))){

		return -1e18;
	}
	//base case
 if(r1==n-1&&c1==m-1&&r2==n-1&&c2==m-1){
	return arr[r1][c1];
 }
//cache check
if(dp[r1][c1][r2]!=-1e18){
return dp[r1][c1][r2];
}
// transition
int ans = ((r1==r2 && c1 == c2)?arr[r1][c1]:arr[r1][c1]+arr[r2][c2]);

ans = ans+max({rec(r1+1,c1,r2+1), rec(r1,c1+1,r2+1),rec(r1+1,c1,r2),rec(r1,c1+1,r2)});
return dp[r1][c1][r2] = ans;
}


void solve(){
	cin>>n>>m;
	for(int i=0; i<n;i++ ){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
			// dp[i][j] = -1e18
		}
	}

	memset(dp, -1e18, sizeof(dp)); //use loops not memset
	cout<<rec(0,0,0,0);
	
}

signed main(){
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}

*/