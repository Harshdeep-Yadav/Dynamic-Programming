// ```````````````````````````recursive soln.`````````````````
#include<bits/stdc++.h>
int f(int ind,vector<int>&heights){
    if(ind==0) return 0;
    int left=f(ind-1,heights)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1) right =f(ind-2,heights)+abs(heights[ind])-heights[ind-2]);
    return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    return f(n-1,heights);
}

// ```````````````````````````````memoization soln.``````````````````````````

#include<bits/stdc++.h>
int f(int ind,vector<int>&heights,vector<int>&dp)
{
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1){
        right =f(ind-2,heights,dp)+abs(heights[ind])-heights[ind-2]);
    }
         
    return dp[ind]= min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
}

// `````````````````````````tabulation sol````````````````````````````

#include<bits/stdc++.h>

int frogJump(int n, vector<int> &height)
{
    vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
    return dp[n-1];
}