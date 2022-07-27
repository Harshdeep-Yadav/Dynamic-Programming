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