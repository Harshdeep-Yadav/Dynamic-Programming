
//                      recursion

int f(vector<int>&price,int ind ,int T)
{
    if(ind==0)
    {
        return T*price[0];
    }
    int nottake=0+f(price,ind-1,T);
    int take =0;
    int rod_length=ind+1;
    if(rod_length<=T)
        take =price[ind]+f(price,ind,T-rod_length);
    return max(take,nottake);
}

int cutRod(vector<int> &price, int n)
{
//     int s=price.size();
    return f(price,n-1,n);
}
//                          memo


int f(vector<int>&price,int ind ,int T,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        return T*price[0];
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    int nottake=0+f(price,ind-1,T,dp);
    int take =0;

    int rod_length=ind+1;
    if(rod_length<=T)
        take =price[ind]+f(price,ind,T-rod_length,dp);
    return dp[ind][T]=max(take,nottake);
}

//                          tabulation

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int N=0;N<=n;N++){
        dp[0][N]=N*price[0];    
    }
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
                int nottake=0+dp[ind-1][N];
                int take =0;

                int rod_length=ind+1;
                if(rod_length<=N)
                    take =price[ind]+dp[ind][N-rod_length];
                dp[ind][N]=max(take,nottake);
        }
    }
    return dp[n-1][n];
}


//          space optimization'



int cutRod(vector<int> &price, int n)
{
    vector<int>prev(n+1,0),curr(n+1,0);
    for(int N=0;N<=n;N++){
        prev[N]=N*price[0];    
    }
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
                int nottake=0+prev[N];
                int take =0;

                int rod_length=ind+1;
                if(rod_length<=N)
                    take =price[ind]+curr[N-rod_length];
                curr[N]=max(take,nottake);
        }
        prev=curr;
    }
    return prev[n];
}
