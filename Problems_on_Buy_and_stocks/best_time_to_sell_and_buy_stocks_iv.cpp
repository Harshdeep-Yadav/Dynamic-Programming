class Solution {
public:
    
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
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
                for(int cap=1;cap<=k;cap++){
                    int profit=0;

                                    if(buy==1){
                                        dp[ind][buy][cap] =max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                                            }
                                    else
                                        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                                        
            
        }
    }
}
       
        return dp[0][1][k];
    }
};




















