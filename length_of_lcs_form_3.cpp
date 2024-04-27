#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int inf = 1e9;

string A,B;
int n, m;
vector<vector<int>> dp;

int lcs(int i, int j){
	//base case
	if(i==-1 || j==-1){
		return 0;
	} 
	// chache check
	if(dp[i][j]!=-1){
		// already computed
		return dp[i][j];
	}
	
	// transition
	
	if(A[i]==B[j]){
		dp[i][j] = lcs(i-1, j-1)+1;
	}else{
		dp[i][j] = max(lcs(i, j-1), lcs(i-1,j));
	}
	
	return dp[i][j];
	
}


int main(){
	fio;
	cin>>A>>B;
	int n = (int A).length();
	int m = (int B).length();
	
	dp.resize(dp.resize(vector<int>(n,vector<int>(m,-1))));
	cout<< lcs(n-1,m-1)<<endl;
	return 0;

	
}