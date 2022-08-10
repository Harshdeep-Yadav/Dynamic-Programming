class Solution {
public:
    int f(int ind ,int buy,int cap,vector<int>&prices)
    {
        int siz=prices.size();
        if(cap==0) return 0;
        if(ind==siz) return 0;
        
        int profit=0;
        
        if(buy){
            return profit=max(-prices[ind]+f(ind+1,0,cap,prices),0+f(ind+1,1,cap,prices));
        }
        else{
            return profit=max(prices[ind]+f(ind+1,1,cap-1,prices),0+f(ind+1,0,cap,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return f(0,1,2,prices);
    }
};


class Solution {
public:
    int f(int ind ,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
        int siz=prices.size();
        if(cap==0) return 0;
        if(ind==siz) return 0;
        
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        
        if(buy){
            return profit=max(-prices[ind]+f(ind+1,0,cap,prices,dp),0+f(ind+1,1,cap,prices,dp));
        }
        else{
            return profit=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),0+f(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};




class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        // when cap==0
//         for(int ind =0;ind<=n;ind++){
//             for(int buy=0;buy<=1;buy++){
//                 dp[ind][buy][cap]=0;
//             }    
//         }
        
//         // when ind=n
//         for(int buy=0;buy<=1;buy++){
//             for(int cap=0;cap<=2;cap++){
//                 dp[n][buy][cap]=0;
//             }    
//         }
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=0;

                                    if(buy==1){
                                        dp[ind][buy][cap] =max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                                            }
                                    else
                                        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                                        
            
        }
    }
}
       
        return dp[0][1][2];
    }
};




















