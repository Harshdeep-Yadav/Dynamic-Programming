class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int profit=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i]){
                profit=profit+prices[i+1]-prices[i];
            }
        }
        return profit;
    }
    
};


class Solution {
    
public:
    
    int f(int ind,int buy,vector<int>&prices)
    {
        int siz=prices.size();
        if(ind==siz) return 0;
        
        int profit=0;
        
        if(buy){
            int take=-prices[ind]+f(ind+1,0,prices);
            int nottake=0+f(ind+1,1,prices);
            return profit= max(take,nottake);
        }
        else
        {
             return profit=max(prices[ind] +f(ind+1,1,prices),0+f(ind+1,0,prices));
        }
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return f(0,1,prices);
    }
    
};




class Solution {
    
public:
    
    int f(int ind,int buy,vector<int>&prices,vector<vector<int>>& dp)
    {
        int siz=prices.size();
        if(ind==siz) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        
        if(buy){
            int take=-prices[ind]+f(ind+1,0,prices,dp);
            int nottake=0+f(ind+1,1,prices,dp);
            return profit= max(take,nottake);
        }
        else
        {
             return profit=max(prices[ind] +f(ind+1,1,prices,dp),0+f(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
    
};




class Solution {
    
public:
    
   
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        dp[n][0]=dp[n][1]=0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                
                int profit=0;
                
                if(buy){
                    profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);    
                }
                else
                     profit=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
            
             dp[ind][buy]=profit;
            }
        }
      return  dp[0][1];
    }
    
};

































