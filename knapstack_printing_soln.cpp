#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int n;
int w[3003];
int v[3003];
int W;
int dp[3003][3003];
// O(n*w)
int rec(int i, int x){ //level and capacity
	//pruning
	//basecase
	if(i==n){
		return 0;
	}
	//cache check
	if(dp[i][x]!=-1){ // if the value corresponding to it is not saved then return it and save 
		return dp[i][x];
	}
	//transition
	int ans = rec(i+1,x);//dont take
	if(w[i]<=x){
		ans= max(ans,rec(i+1,x-w[i])+v[i]);
	}
	//save and return 
	dp[i][x] = ans;
	return ans;
	
}


vector<int> solution;
void generate(int i, int x){
	if(i==n){
		return;
	}else{
		int donttake=rec(i+1,x);
		if(w[i]<=x){
			//can possibly take
			int take = rec(i+1,x-w[i])+v[i];
			if(donttake>take){ //if donttake is better than take then move to next level
				generate(i+1,x);
				
			}else{
				solution.push_back(i); // takr
				generate(i+1,x-w[i]);
			}
		}else{
			//can't take
			generate(i+1,x);
		}
	}
}

void solve(){
	cin>>n;
	for(int i=0;i<n; i++){
		cin>>w[i];
	}
	for(int i=0;i<n; i++){
		cin>>v[i];
	}
	cin>>W;
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,W)<<endl;
	generate(0,W);//O(1)
	cout<<solution.size()<<endl;
	for(auto v:solution){
		cout<<v<<" ";
	}
	cout<<endl;
}


int main(){
fio;
		solve();
}
		
