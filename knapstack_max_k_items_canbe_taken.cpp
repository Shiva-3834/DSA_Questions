#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n;
int w[3003];
int v[3003];
int W,k;
int dp[101][101][101 ];
int rec(int i, int x,int item_left){ //level and capacity
	//max value you can make in [i...n],where x is the weight left and
	// item_left is the number of item left to be taken at max.
	
	//pruning
	//basecase
	if(i==n){
		return 0;
	}
	//cache check
	if(dp[i][x][item_left]!=-1){ // if the value corresponding to it is not saved then return it and save 
		return dp[i][x][item_left];
	}
	//transition
	int ans = rec(i+1,x,item_left);//dont take
	if(w[i]<=x && item_left>0){
		ans= max(ans,rec(i+1,x-w[i],item_left-1)+v[i]);
	}
	//save and return
	dp[i][x][item_left] = ans;
	return ans;
	
}


void solve(){
	cin>>n;
	for(int i=0;i<n; i++){
		cin>>w[i]>>v[i];
	}
	for(int i=0;i<n; i++){
		cin>>v[i];
	}
	cin>>W>>k;
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,W,k)<<endl;
}


int main(){
fio;
		solve();
}
		
