// class Solution {
    
// public:
    
//     int f(int ind,int buy,vector<int>&prices,int fee)
//     {
//         int siz=prices.size();
//         if(ind==siz) return 0;
        
//         int profit=0;
        
//         if(buy){
//             int take=-prices[ind]+f(ind+1,0,prices,fee);
//             int nottake=0+f(ind+1,1,prices,fee);
//             return profit= max(take,nottake);
//         }
//         else
//         {
//              return profit=max(prices[ind]-fee +f(ind+1,1,prices,fee),0+f(ind+1,0,prices,fee));
//         }
//         return profit;
//     }
    
//     int maxProfit(vector<int>& prices,int fee) {
//         int n=prices.size();
//         return f(0,1,prices,fee);
//     }
    
// };



//```````````tabulation solution```````````````

class Solution {  
public:
     int maxProfit(vector<int>& prices,int fee) { 
        int ans = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, hold + prices[i] - fee);
            hold = max(hold, ans - prices[i]);
        }
        return ans;
//         int n=prices.size();
        
//         vector<vector<int>> dp(n+1,vector<int>(2,0));
        
//         dp[n][0]=dp[n][1]=0;
        
//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<=1;buy++){
                
//                 int profit=0;
                
//                 if(buy){
//                     profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);    
//                 }
//                 else
//                      profit=max(prices[ind]-fee+dp[ind+1][1],dp[ind+1][0]);
            
//              dp[ind][buy]=profit;
//             }
//         }
//       return  dp[0][1];
    }
    
};


