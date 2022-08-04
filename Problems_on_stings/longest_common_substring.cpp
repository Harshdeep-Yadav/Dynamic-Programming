 // tabulation method
 
  int longestCommonSubstr (string S1, string S2, int n, int m)
    
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        return ans;
    }

// space optimization
    int lcs(string &S1, string &S2){
    int n=S1.size();
    int m=S2.size();
	  vector<int> prev(n+1,0),curr(m+1,0);
        // for(int i=0;i<=n;i++) dp[i][0]=0;
        // for(int j=0;j<=m;j++) dp[0][j]=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    curr[j]=1+prev[j-1];
                    ans=max(ans,curr[j]);
                }
                else
                    curr[j]=0;
            }
            prev=curr;
        }
        return ans;
}