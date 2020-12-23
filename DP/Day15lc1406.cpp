class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n=stones.size();
        vector<pair<int,int>> dp(n+1,{0,0});
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
               dp[i]={stones[n-1],0}; 
            }
            else if(i==n-2){
                if(stones[i]+dp[i+1].second>stones[i]+stones[i+1]) dp[i]={stones[i]+dp[i+1].second,dp[i+1].first};
                else dp[i]={stones[i]+stones[i+1],0};
            }
            else{
                int sum=stones[i]+stones[i+1]+stones[i+2];
                dp[i]={stones[i]+stones[i+1]+dp[i+2].second,dp[i+2].first};
                if(sum+dp[i+3].second>stones[i]+stones[i+1]+dp[i+2].second) dp[i]={sum+dp[i+3].second,dp[i+3].first};
                if(dp[i].first<stones[i]+dp[i+1].second) dp[i]={stones[i]+dp[i+1].second,dp[i+1].first};
            }
        }
        if(dp[0].first==dp[0].second) return "Tie";
        if(dp[0].first>dp[0].second) return "Alice";
        return "Bob";
    }
};
