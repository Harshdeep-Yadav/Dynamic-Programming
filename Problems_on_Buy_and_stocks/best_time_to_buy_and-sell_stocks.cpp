class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        int profit=0;
        int min=prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
            }
            else if(prices[i]-min>profit)
            {
                   profit=prices[i]-min ;
            }
        }
        return profit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
           int cost=prices[i]-mini;
           profit=max(profit,cost);
           mini=min(prices(i),mini);
        }
        return profit;
    }
};
