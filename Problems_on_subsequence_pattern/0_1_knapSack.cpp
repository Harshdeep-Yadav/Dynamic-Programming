// ``````````````````recursion solution````````````````````````
int f(int ind,int w,vector<int>&wt,vector<int>&val)
{
    if(ind==0){
         if(wt[0]<=w) return val[0];
        else
            return 0;
     }
   
    int notpick=0+f(ind-1,w,wt,val);
    int pick=INT_MIN;
    if(wt[ind]<=w)
        pick=val[ind]+f(ind-1,w-wt[ind],wt,val);
    return max(pick,notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

    return f(n-1,maxWeight,weight,value);
}



// ``````````````````Memoization  solution````````````````````````


int f(int ind,int w,vector<int>&wt,vector<int>&val,vector<vector<int>> &dp)
{
    if(ind==0){
         if(wt[0]<=w) return val[0];
        else
            return 0;
     }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notpick=0+f(ind-1,w,wt,val,dp);
    int pick=INT_MIN;
    if(wt[ind]<=w)
        pick=val[ind]+f(ind-1,w-wt[ind],wt,val,dp);
    return dp[ind][w]=max(pick,notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return f(n-1,maxWeight,weight,value,dp);
}


//``````````````````````tabulation solution``````````````````````


 int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int i=weight[0];i<=maxWeight;i++) dp[0][i]= value[0];
     
     for(int ind=1;ind<n;ind++){
         for(int W=0;W<=maxWeight;W++){
                    int notpick=0+dp[ind-1][W];
                    int pick=INT_MIN;
                    if(weight[ind]<=W)
                        pick=value[ind]+dp[ind-1][W-weight[ind]];
                 dp[ind][W]=max(pick,notpick);
         }
     }
     return dp[n-1][maxWeight];
}


//```````````````````space optomization````````````````````````````

 int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);
    for(int i=weight[0];i<=maxWeight;i++) prev[i]= value[0];
     
     for(int ind=1;ind<n;ind++){
         for(int W=0;W<=maxWeight;W++){
                    int notpick=0+prev[W];
                    int pick=INT_MIN;
                    if(weight[ind]<=W)
                        pick=value[ind]+prev[W-weight[ind]];
                 curr[W]=max(pick,notpick);
         }
         prev=curr;
     }
     return prev[maxWeight];
}

