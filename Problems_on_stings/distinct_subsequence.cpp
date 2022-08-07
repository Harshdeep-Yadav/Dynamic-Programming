// ```````````````````recursion```````````````

// class Solution {
// public:
//     int f(int i,int j,string s,string t){
        
//         if(j<0) return 1;
//         if(i<0) return 0;
        
//         if(s[i]==t[j]){
//             return f(i-1,j-1,s,t)+f(i-1,j,s,t);
//         }
//         else
//             return f(i-1,j,s,t);
//     }
//     int numDistinct(string s, string t) {
//         int n=s.size();
//         int m=t.size();
        
//         return f(n-1,m-1,s,t);
//     }
// };

// `````````````````memoization```````````````````

// class Solution {
// public:
//     int f(int i,int j,string s,string t,vector<vector<int>> dp){
        
//         if(j<0) return 1;
//         if(i<0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==t[j]){
//             int both= f(i-1,j-1,s,t,dp);
//             int nottake=f(i-1,j,s,t,dp);
//             return dp[i][j]=both+nottake;
//         }
//         else
//             return dp[i][j]= f(i-1,j,s,t,dp);
//     }
//     int numDistinct(string s, string t) {
//         int n=s.size();
//         int m=t.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         return f(n-1,m-1,s,t,dp);
//     }
// };

// ````````````````````tabulation````````````````


// class Solution {
// public:

//     int numDistinct(string s, string t) {
//         int n=s.size();
//         int m=t.size();
//         vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        
//         // base case----------
        
//         for(int i=0;i<=n;i++) dp[i][0]=1;

//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                   if(s[i-1]==t[j-1])
//                   {
//                         dp[i][j]= dp[i-1][j-1]+dp[i-1][j] ;
//                   }
//                 else
//                      dp[i][j]= dp[i-1][j];
//             }
//         }
//         return dp[n][m];
//     }
// };


//```````````````space optimization ```````````````````


















