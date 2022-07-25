//`````````````recursive solution````````````````

int f(int i,int j,vector<vector<int>> &mat){
    if(i>=0&&j>=0&&mat[i][j]==-1) return 0;
    if(i==0&&j==0) return 1;
    if(i<0||j<0) return 0;
    int up=f(i-1,j,mat);
    int left=f(i,j-1,mat);
    
    return up+left;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
   return f(m-1,n-1,mat);
}

// ``````````````memoization solution``````````````


int f(int i,int j,vector<vector<int>> &mat, vector<vector<int>>& dp ){
    if(i>=0&&j>=0&&mat[i][j]==-1) return 0;
    if(i==0&&j==0) return 1;
    if(i<0||j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=f(i-1,j,mat);
    int left=f(i,j-1,mat);
    
    return dp[i][j]=up+left;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
   return f(m-1,n-1,mat,dp);
}

