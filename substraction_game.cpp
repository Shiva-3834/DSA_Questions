#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;


int dp[100100];

vector<int>moves={1,3,4};
int rec(int x)
{
    // base case
    if (x==0)return 0;


    // cache check
    if (dp[x]!=-1)
    {
        return dp[x];
    }

    int ans = 0;
    for(auto v:moves){
        if(v<=x && rec(x-v)==0){ //picking the larger one or if the rec value 0 means losing state
            ans =1;
            break;
        }
    }

    return dp[x] = ans;
}

void solve()
{
    cin >> n;
    // dp soln
    memset(dp,-1,sizeof(dp));

    for (int i = 0; i <=20; i++)
    {
        cout<<i<<" "<<rec(i)<<endl;
    }

    // if we have n upto 10^5 then will use the dp method 

// if we have n as 10^18 then will use the observation method 


   // by observation
   if(n%7==0||n%7==2){
    cout<<"Lose"<<endl;
   }else{
    cout<<"Win"<<endl;
   }
  
}

#undef int

int main()
{

    solve();
}