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
int rec(int level){ // return -> no.of ways to N 
// level -> stair I'm at
	
	
	// pruning
	if(level>n){
		return 0;
	}
	
	//base case
	if(level == n){
		return 1;
	}
	
	int ans =0;
	// loop over choice
	for(int step = 1; step<=3; step++){
		if(level+step<=n){
			//check -> is a valid choice
			int ways = rec(level+step); //move
			ans+=ways;
		}
	}
  return ans; //for this level	
}



void solve(){
	int n;
	cin>>n;
	
	
	
  }
	

signed main() {
	fio;
    int t=1;
    cin>>t;
while(t--){
	solve();
}   
}
