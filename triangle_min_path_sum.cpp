
//````````````recursion solution````````````````````


int f(int i,int j,vector<vector<int>>&triangle,int n){
    if(i==n-1) return triangle[i][j];
    int down=triangle[i][j]+f(i+1,j,triangle,n);
    int diagonal=triangle[i][j]+f(i+1,j+1,triangle,n);
    return  min(down,diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	return f(0,0,triangle,n);
}

//````````````memoization solution````````````````````

int f(int i,int j,vector<vector<int>>&triangle,int n,vector<vector<int>>&dp){
    if(i==n-1) return triangle[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down=triangle[i][j]+f(i+1,j,triangle,n,dp);
    int diagonal=triangle[i][j]+f(i+1,j+1,triangle,n,dp);
    return dp[i][j]= min(down,diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(0,0,triangle,n,dp);
}


//````````````tabulation solution````````````````````

int minimumPathSum(vector<vector<int>>&triangle,int n)
{
    int dp[n][n];
    for(j=0;j<n;j++){
        dp[n-1][j]=triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=triangle[i][j]+dp[i+1][j];
            int digonal=triangle[i][j]+dp[i+1][j+1]
            dp[i][j]=min(down,digonal);
        }
    }
    return dp[0][0];
}

// `````````space optimizatoin`````````

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
   vector<int> front(n,0),cur(n,0);
    for(int j=0;j<n;j++){
        front[j]=triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down=triangle[i][j]+front[j];
            int digonal=triangle[i][j]+front[j+1];
            cur[j]=min(down,digonal);
        }
        front=cur;
    }
    return front[0];
    }
};