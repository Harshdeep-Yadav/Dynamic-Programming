// ``````````````````````recursion solution```````````````

class Solution {
public:
    int f(int ind,int a,vector<int>&coins){
        if(ind==0)
            return (a%coins[0]==0);
        // if(dp[ind][a]!=-1) return dp[ind][a];
        int nottake=f(ind-1,a,coins);
        int take=0;
        if(coins[ind]<=a)
            take=f(ind,a-coins[ind],coins;
        return dp[ind][a]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins);
    }
};


// `````````````````memoization solution```````````````````````````
class Solution {
public:
    int f(int ind,int a,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0)
            return (a%coins[0]==0);
        if(dp[ind][a]!=-1) return dp[ind][a];
        int nottake=f(ind-1,a,coins,dp);
        int take=0;
        if(coins[ind]<=a)
            take=f(ind,a-coins[ind],coins,dp);
        return dp[ind][a]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};

