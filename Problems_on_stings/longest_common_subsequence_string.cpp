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


int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<m;j++) dp[0][j]=0;
    for(int i=0;i<n;i++) dp[i][i]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
            else
                dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];
}


