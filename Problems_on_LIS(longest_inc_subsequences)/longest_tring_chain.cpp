class Solution {
       
    public:
    
//     static bool comp(string &s1,string&s2){
//         return s1.size()<s2.size();
//     }

    
   
//     bool checkPossible(string &s1,string &s2){
//         if(s1.size()!=s2.size()+1) return false;
//         int first=0;
//         int second=0;
        
//         while(first<s1.size()){
//             if(s1[first]==s2[second]){
//                 first++;
//                 second++;
//             }
//             else
//                 first++;
            
//             if(s1[first]==s1.size()&&s2[second]==s2.size())
//                 return true;
//         }
//         return false;          
// }
 
    
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(),words.end(),comp);
//         int n=words.size();
//         int maxi=1;
//         vector<int> dp(n,1);
//         for(int i=0;i<=n-1;i++){
//             for(int j=0;j<=i-1;j++){
//                 if(checkPossible(words[i],words[j])&& dp[i]<1+dp[j]){
//                     dp[i]=1+dp[j];
//                 }
//             }
//         if(dp[i]>maxi){
//             maxi=dp[i];
//             }
        
//         return maxi;
//     }
// };



	static bool comp(string s1, string s2){
        return s1.size() < s2.size();
    }
    
    bool issubseq(string &s1, string &s2){
        int i=0,j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                i++;j++;
            }
            else{
                j++;
            }
        }
        
        return i==s1.size();
    }
    
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        
        int maxi = 1;
        sort(words.begin(),words.end(),comp);
        
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(words[j].size()+1 == words[i].size() && issubseq(words[j],words[i]) && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        return maxi;
    }
};
