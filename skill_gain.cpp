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
 

 int taken[1001];
 
 bool check(int level){
 	int timetaken =0;
 	int itemtaken= 0;
 	for(int i=0; i<level;i++){
 		if(taken[i]){
 			timetaken +=t[i];
 			itemtaken +=1;
 		}
 	}
 	timetaken+= t[level];
 	itemtaken++;
 	
 	if(itemtaken<=x && itemtaken<=k){
 		return 1;
 	}else {
 		return 0;
 	}
 	
 }
 
int rec(int level){ 
	
	
	// pruning
	
	
	//base case
	if(level==n){
		return 0;
	}
	// compute
	//loop over choice
	// choice 1: dont take
	int ans = rec(level+1);
	// choice 2: take
	if(check(level)){
		//place the change 
		taken[level] =1;
		//move
		ans = max(ans,s[level]+rec(level+1));
		//revert 
		taken[level]=0;
	}
	
	// return 
  return ans; 	
}



void solve(){
	int n;
	cin>>n;
	for(int i =0; i<n; i++){
		cin>>t[i]>>s[i];
	}
	cin>>x>>k;
	
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
