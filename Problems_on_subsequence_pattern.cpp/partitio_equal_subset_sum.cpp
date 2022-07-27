class Solution {
public:
    bool subsetsum(vector<int>&nums,int k,int ind=0)
    {
        int n =nums.size();
        if(k==0) return true;
        if(ind==0) return (nums[0]==k);
        
        bool nottake=subsetsum(nums,n-1,k);
        bool take=false;
        if(k>=nums[ind]) 
            take=subsetsum(nums,n-1,k);
        return take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
       int totSum = accumulate(begin(nums), end(nums), 0);
        if(totSum%2) return false;
        int target=totSum/2;
        
            return subsetsum(nums,target);
    }
};






//````````````````````````````````````````
class Solution {
public:
    int dp[201][10001] = {[0 ... 200] = {[0 ... 10000] = -1}};  // all initialized to -1 (use dynamic vector to generalize to higher array size & possible sums)
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if(totalSum & 1) return false;
        return subsetSum(nums, totalSum / 2);
    }
    bool subsetSum(vector<int>& nums, int sum, int i = 0) {
        if(sum == 0) return true;
        if(i >= size(nums) || sum < 0) return false; 
        if(dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = subsetSum(nums, sum - nums[i], i + 1) || subsetSum(nums, sum, i + 1);
    }
};