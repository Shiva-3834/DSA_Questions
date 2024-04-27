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
 int queen[20]; //queen[i] -> where is my queen in row i.
 
 bool check(int row, int col){
 	for(int i=0; i<row; i++){
 		int prow =i;
 		int pcol = queen[i];
 		
 		if(pcol==col || abs(col-pcol) == abs(row-prow)){
 			return 0; 
 		}
 	}
 	return 1;
 }
 
 
 
int rec(int level){ //rec -> no.of ways to populate [level..n-1] rows for a valid configuration
// level -> row in which I'm placing the queen'
	
	
	// pruning
	
	
	//base case
	if(level==n){
		return 1;
	}
	
	// compute
	int ans =0;
	// loop over all the choices
	for(int col=0; col<n; col++){
		if(check(level,col)){
			//place the queen
			 queen[level] = col;
			 //explore the option
			ans+=  rec(level+1);
			//revert placing the queen
			 queen[level] = -1;
		}
	}
	// return 
  return ans; 	
}



void solve(){
	int n;
	cin>>n;
	memset(queen,-1,sizeof(queen));
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
