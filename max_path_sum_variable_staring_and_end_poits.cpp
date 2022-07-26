
//`````````````recursive solution````````````````````

int f(int i,int j,vector<vector<int>>&matrix){
       if(j<0||j>=matrix[0].size()) return -1e7;
       if(i==0) return matrix[i][j];
       int s=matrix[i][j]+f(i-1,j,matrix);
       int l=matrix[i][j]+f(i-1,j-1,matrix);
       int r=matrix[i][j]+f(i-1,j+1,matrix);
       return max(s,max(l,r));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m =matrix[0].size();
    int maxi=-1e8;
   
    for(int j=0;j<m;j++){

       maxi=max(maxi, f(n-1,j,matrix));
    }
    return maxi;
}

//`````````````````memoization solution``````````````

int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>& dp){
       if(j<0||j>=matrix[0].size()) return -1e7;
       if(i==0) return matrix[i][j];
       if(dp[i][j]!=-1) return dp[i][j];
       int s=matrix[i][j]+f(i-1,j,matrix,dp);
       int l=matrix[i][j]+f(i-1,j-1,matrix,dp);
       int r=matrix[i][j]+f(i-1,j+1,matrix,dp);
       return dp[i][j]= max(s,max(l,r));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m =matrix[0].size();
    int maxi=-1e8;
   vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int j=0;j<m;j++){

       maxi=max(maxi, f(n-1,j,matrix,dp));
    }
    return maxi;
}

// ``````````````````tabulation solution```````````````

int getMaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,0));
    
    // Initializing first row - base condition
    for(int j=0; j<m; j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<m;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;
}