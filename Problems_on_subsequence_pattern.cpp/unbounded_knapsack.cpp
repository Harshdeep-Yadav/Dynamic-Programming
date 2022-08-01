//```````````````````Recursion solution````````````````````

#include<bits/stdc++.h> 
int f(int ind,int W,vector<int>&p,vector<int>&wt)
{
    // base case 
    if(ind==0){
        return (int)(W/wt[0])*p[0];
    }
    int nottake=0+f(ind-1,W,p,wt);
    int take =INT_MIN;
    if(wt[ind]<=W) 
        take=p[ind]+f(ind,W-wt[ind],p,wt);
    return max(take,nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return f(n-1,w,profit,weight);
}


//`````````````````memoization solution````````````````````````````````````


int f(int ind,int W,vector<int>&p,vector<int>&wt,vector<vector<int>>&dp)
{
    // base case 
    if(ind==0){
        return (int)(W/wt[0])*p[0];
    }
    if(dp[ind][W]!=-1) return dp[ind][W];
    int nottake=0+f(ind-1,W,p,wt,dp);
    int take =INT_MIN;
    if(wt[ind]<=W)
        take=p[ind]+f(ind,W-wt[ind],p,wt,dp);
    return max(take,nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return f(n-1,w,profit,weight,dp);
}

// ``````````````tabulation solution ````````````````


int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = 0;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}

// `````````````````space optimization solution ```````````````````


int unboundedKnapsack(int n, int W, vector<int>& val,vector<int>& wt) {
    
vector<int> prev(W+1,0),curr(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        prev[i] = ((int) i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + prev[cap];
            
            int taken = 0;
            if(wt[ind] <= cap)
                taken = val[ind] + curr[cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
        prev=curr;
    }
    
    return prev[W];
}