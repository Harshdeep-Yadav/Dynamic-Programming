// ``````````````````recurive solution``````````````````````

int f(int i,int j){
    if(i==0&&j==0) return 1;
    if(i<0||j<0) return 0;
    int up=f(i-1,j);
    int left f(i,j-1);
    
    return up+left;
}

int uniquePaths(int m, int n) {
	return f(m-1,n-1);
}

// ``````````````````memoization solution``````````````````````
int mod= 1e9+7
int f(int i,int j,vector<vector<int>> &dp){
    if(i==0&&j==0) return 1;
    if(i<0||j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=f(i-1,j,dp);
    int left =f(i,j-1,dp);
    return dp[i][j]=(up+left)%mod;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return f(m-1,n-1,dp);
}

// `````````````````````tabulation solution `````````````
int mod=(int)(1e9+7);

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
   int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1) dp[i][j]=0;
            else if(i==0&&j==0) dp[i][j]=1;
            else{
                int up=0;
                int left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=(up+left    )%mod;
            }
        }    
    }
    return dp[m-1][n-1];
    
}