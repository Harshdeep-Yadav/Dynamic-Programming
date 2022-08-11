
// ```````````````````recursion solution````````````````````

class Solution {
public:
    int f(int ind,int prev_ind,vector<int> nums)
    {
        int siz=nums.size();
        if(ind==siz) return 0;
        
        int nottake=0+f(ind+1,prev_ind,nums);
        
        int take=0;
        if(prev_ind==-1||nums[ind]>nums[prev_ind])
        {
             take+=1+f(ind+1,ind,nums);
        } 
        int ans=max(nottake,take);
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return f(0,-1,nums);
    }
};

//`````````````````memoization solution`````````````````

class Solution {
public:
   
    int f(int ind,int prev_ind,vector<int> nums,vector<vector<int>> &dp){
        int siz=nums.size();
        if(ind==siz) return 0;
        
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1]; // adding 1 in prev_ind because we have done coordinate changes 
        
        int nottake=0+f(ind+1,prev_ind,nums,dp);
        int take=0;
        if(prev_ind==-1||nums[ind]>nums[prev_ind])
        {
            take+=1+f(ind+1,ind,nums,dp);
        }
        int ans=max(nottake,take);
        
        return dp[ind][prev_ind+1]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};

//````````````````````tabulation solution```````````````````````

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_ind = ind-1; prev_ind >=-1; prev_ind --){
            
            int notTake = 0 + dp[ind+1][prev_ind +1];
    
            int take = 0;
    
            if(prev_ind== -1 || nums[ind] > nums[prev_ind]){
                
                take = 1 + dp[ind+1][ind+1];
            }
    
            dp[ind][prev_ind+1] = max(notTake,take);
            
        }
    }
    
    return dp[0][0];

    }
};