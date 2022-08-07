// class Solution {
// public:
//     int f(int i,int j,string s,string t )
//     {
//         if(i<0) return j+1;
//         if(j<0) return i+1;
//         if(s[i]==t[j])
//             return 0+f(i-1,j-1,s,t);
//         else
//             return 1+min(f(i,j-1,s,t),min(f(i-1,j,s,t),f(i-1,j-1,s,t)));
//     }
//     int minDistance(string s, string t) {
//         int n=s.size();
//         int m=t.size();
        
//         return f(n-1,m-1,s,t);
//     }
// };


// class Solution {
// public:
//     int f(int i,int j,string s,string t ,vector<vector<int>> dp)
//     {
//         if(i<0) return j+1;
//         if(j<0) return i+1;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==t[j])
//             return dp[i][j]= 0+f(i-1,j-1,s,t,dp);
//         else
//             return dp[i][j]=1+min(f(i,j-1,s,t,dp),min(f(i-1,j,s,t,dp),f(i-1,j-1,s,t,dp)));
//     }
//     int minDistance(string s, string t) {
//         int n=s.size();
//         int m=t.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         return f(n-1,m-1,s,t,dp);
//     }
// };


class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                 if(s[i-1]==t[j-1])
                     dp[i][j]= 0+dp[i-1][j-1];
                 else
                     dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));   
            }
        }
        return dp[n][m];
    }
};
                                                         
                                                         
                                                         
                                                         
                                                         