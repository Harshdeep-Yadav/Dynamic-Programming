class Solution {
public:
    bool isPalindrome(int i,int j,string&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
                i++;
                j--;    
        }
        return true;
    }
    int f(int i,int j,string &s)
    {
        int n=s.size();
        if(i==n) return 0;
        int costMin=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+f(j+1,n,s);
                costMin=min(costMin,cost);
            }
        }
        return costMin;
    }
    int minCut(string s) {
        int n=s.size();
        return f(0,n,s)-1;
    }
};


class Solution {
public:
    bool isPalindrome(int i,int j,string&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
                i++;
                j--;    
        }
        return true;
    }
    int f(int i,int j,string &s,vector<int> &dp)
    {
        int n=s.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int costMin=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+f(j+1,n,s,dp);
                costMin=min(costMin,cost);
            }
        }
        return dp[i]= costMin;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return f(0,n,s,dp)-1;
    }
};



class Solution {
public:
    bool isPalindrome(int i,int j,string&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
                i++;
                j--;    
        }
        return true;
    }

    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
             int costMin=INT_MAX;
             for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                int cost=1+dp[j+1];
                costMin=min(costMin,cost);
                }
            }
            dp[i]=costMin;
        }
        return dp[0]-1;
    }
};