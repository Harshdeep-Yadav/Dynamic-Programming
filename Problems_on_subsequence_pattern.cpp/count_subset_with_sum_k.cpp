//```````````````````recursive solution````````````````

int f(int ind,int k,vector<int>&num)
{
     if(k==0) return 1;
    if(ind==0) return (num[0]==k);
    
    int notpick=f(ind-1,k,num);
    int pick=0;
    if(num[ind]<=k) pick=f(ind-1,k-num[ind],num);
    
    return pick+notpick;
}
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    return f(n-1,tar,num);
}

//``````````````````memoization solution`````````````````````````

int f(int ind,int k,vector<int>&num,<vector<int>> &dp)
{
     if(k==0) return 1;
    if(ind==0) return (num[0]==k);
    if(dp[ind][k]!=-1) return dp[ind][k];
    int notpick=f(ind-1,k,num,dp);
    int pick=0;
    if(num[ind]<=k) pick=f(ind-1,k-num[ind],num,dp);
    
    return dp[ind][k]=pick+notpick;
}
//`````````````````````````tabulation`````````````````````
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,tar,num,dp);
}


//`````````````````````space opt ``````````````
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
     vector<vector<int>> dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++) dp[i][0] = 1;
    if(num[0]<=tar) dp[0][num[0]] = 1;
    
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
                int notpick=dp[ind-1][sum];
                int pick=0;
                if(num[ind]<=tar) 
                    pick=dp[ind-1][sum-num[ind]];
                dp[ind][sum]=pick+notpick;
        }
    }
              return dp[n-1][tar];
}




int findWays(vector<int> &num, int tar)
{
    int n=num.size();
     vector<int>prev(tar+1,0),curr(tar+1);
     prev[0]=curr[0] = 1;
    if(num[0]<=tar) prev[num[0]] = 1;
    
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
                int notpick=prev[sum];
                int pick=0;
                if(num[ind]<=tar) 
                    pick=prev[sum-num[ind]];
                curr[sum]=pick+notpick;
        }
        prev=curr;
    }
              return prev[tar];
}
