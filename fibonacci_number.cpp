#include<iostream>
#include<vector>
using namespace std;

int fibo(int n,vector<int>&dp)
{
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibo(n,dp);
    return 0;

}

#include <bits/stdc++.h>

using namespace std;
//``````````````````````````````````````    Part -2: Tabulation````````````````````````````````

int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}

 // ````````````````````````````````````````Part 3: Space Optimization``````````````````````
#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=5;
  
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}
