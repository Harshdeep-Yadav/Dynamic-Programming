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

//`````````````````````tabulation solution``````````````````

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true; // base case 
    dp[0][arr[0]]=true; // base case 
    
    for(int ind=1;ind<n;ind++){ //index
        for(int target=1;target<k;target++) { // target

            bool nottake=dp[ind-1][target];
            bool take=false;
            if(target>=arr[ind]) take=dp[ind-1][target-arr[ind]]; // recursion
            
            dp[ind][target]=take||nottake;
        }
    }
    return dp[n-1][k];
}


// ```````````````space opt.```````````````````````````````````
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1,false);
    
    prev[0] = true;
    
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    
    return prev[k];
}

