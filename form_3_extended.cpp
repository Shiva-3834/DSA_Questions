#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int inf = 1e9;

string a,b,c;
int n, m,x;
 dp[1001][1001];

int lcs(int i, int j,int k){
	//return LCS of a a[i...n-1] ans b[i...m-1]..c[i...x-1]
	//base case
	if(i>=n || j>=m || k>=x){
		return 0;
	} 
	// chache check
	if(dp[i][j][k]!=-1){
		// already computed
		return dp[i][j][k];
	}
	
	// transition
	int ans =0; 
	ans= max(ans,rec(i+1,j,k));
	ans= max(ans,rec(i,j+1,k));
	ans= max(ans,rec(i,j,k+1));
	
	if(a[i]==b[j] && b[j]==c[k]){
		ans = max(ans,1+rec(i+1,j+1,k+1));
	}
	
	return dp[i][j][k]=ans;
	
}


int main(){
	fio;
	cin>>A>>B;
	int n = (int A).length();
	int m = (int B).length();
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0,0)<<endl;
	
	return 0;

	
}