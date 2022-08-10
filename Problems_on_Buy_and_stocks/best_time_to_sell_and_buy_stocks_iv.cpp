// class Solution {
// public:
    
//     int maxProfit(int k,vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
// //`````````````````base case``````````````````
//         // when cap==0
// //         for(int ind =0;ind<=n;ind++){
// //             for(int buy=0;buy<=1;buy++){
// //                 dp[ind][buy][cap]=0;
// //             }    
// //         }
        
// //         // when ind=n
// //         for(int buy=0;buy<=1;buy++){
// //             for(int cap=0;cap<=2;cap++){
// //                 dp[n][buy][cap]=0;
// //             }    
// //         }
        
//         for(int ind=n-1;ind>=0;ind--){
//             for(int buy=0;buy<=1;buy++){
//                 for(int cap=1;cap<=k;cap++){
//                     int profit=0;
//                   if(buy==1){
//                     dp[ind][buy][cap] =max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap])                              }
//                   else
//                         dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
//                     }
//                 }
//             }
//         return dp[0][1][k];
//     }
// };

// solution using transaction number

// class Solution {
// public: 
//     int f(int ind ,int transNo,int k,vector<int> &prices){
//         int siz=prices.size();
//         if(ind==siz || transNo==2*k) return 0;
        
//         if(transNo%2==0){ // buy
//             return max(-prices[ind]+f(ind+1,transNo+1,k,prices),0+f(ind+1,transNo,k,prices));
//         }
//         return max(prices[ind]+f(ind+1,transNo+1,k,prices),0+f(ind+1,transNo,k,prices));
        
//     }
//     int maxProfit(int k,vector<int>& prices) {
//         int n=prices.size();
//         return f(0,0,k,prices);
//   }
// };




//  ````````````````` memoization-solution`````````````




// class Solution {
// public: 
//     int f(int ind ,int transNo,int k,vector<int> &prices,vector<vector<int>> &dp){
//         int siz=prices.size();
//         if(ind==siz || transNo==2*k) return 0;
        
//         if(dp[ind][transNo]!=-1) return dp[ind][transNo];
        
//         if(transNo%2==0){ // buy
//             return max(-prices[ind]+f(ind+1,transNo+1,k,prices,dp),0+f(ind+1,transNo,k,prices,dp));
//         }
//         return max(prices[ind]+f(ind+1,transNo+1,k,prices,dp),0+f(ind+1,transNo,k,prices,dp));
        
//     }
//     int maxProfit(int k,vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
//         return f(0,0,k,prices,dp);
//   }
// };



// ```````````````tabulation solution````````````````



class Solution {
public: 
   
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int transNo=2*k-1;transNo>=0;transNo--){
                if(transNo%2==0){ // buy
                    dp[ind][transNo]= max(-prices[ind]+dp[ind+1][transNo+1],0+dp[ind+1][transNo]);
                }
                else
                    dp[ind][transNo]= max(prices[ind]+dp[ind+1][transNo+1],0+dp[ind+1][transNo]);
            }
        }
        return dp[0][0];
  } 
};

















