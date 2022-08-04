//``````````````````recursion`````````````````````````

int f(int i,int j,string &s,string&t)
{
    if(i<0||j<0)
    {
        return 0;
    }
    if(s[i]==t[j]){
        return 1+f(i-1,j-1,s,t);
    }
    return max(f(i,j-1,s,t),f(i-1,j,s,t));
}

int lcs(string s, string t)
{
	int n=s.size();
    int m=t.size();
    
    return f(n-1,m-1,s,t);
}

//``````````````````memoization````````````````````````
#include<bits/stdc++.h>
int f(int i,int j,string &s,string&t,vector<vector<int>> &dp)
{
    if(i<0||j<0)
    {
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
        return 1+f(i-1,j-1,s,t,dp);
    }
    return max(f(i,j-1,s,t,dp),f(i-1,j,s,t,dp));
}

int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s,t,dp);
}

//```````````````````tabulation```````````````````````
longestPalinSubstring

