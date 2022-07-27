//`````````````````recursive solution````````````````````````

bool f(int ind ,int target,vector<int>&arr)
{
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
   
    bool Nottake=f(ind -1,target,arr);
    bool take=false;
    if(target>=arr[ind]) take=f(ind-1,target-1,arr);
       
       return take||Nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    return f(n-1,k,arr);
}

//````````````````````memoization solution ``````````````````

bool f(int ind ,int target,vector<int>&arr, vector<vector<int>> &dp)
{
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool Nottake=f(ind -1,target,arr,dp);
    bool take=false;
    if(target>=arr[ind]) take=f(ind-1,target-1,arr,dp);
       
       return dp[ind][target]= take||Nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

