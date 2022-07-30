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

// ```````````````````Tabulation solution ```````````````

class Solution {
public:
  
    int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,0));
//         // base case 
         
//         for(int a=0;a<=amount;a++){
//             dp[0][a]= (amount%coins[0]==0);
//         }

//         for(int ind=1;ind<n;ind++){
//             for(int a=0;a<=amount;a++){
//                 int nottake=dp[ind-1][a];
//                 int take=0;
//                 if(coins[ind]<=a)
//                 take=dp[ind][a-coins[ind]]; 
//                 dp[ind][a]=take+nottake;
//             }
//         }
//         return dp[n-1][amount];
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i<coins.size(); i++){
            for(int j = coins[i]; j<= amount; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};