class Solution {
    //7
    //8  9  10  
    //9 10     8 10     8 9 
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1);
        for(size_t i = 0; i < dp.size(); ++i){
            dp[i] = vector<int>(n+1, -1);
        }
        return memo(1, n, n, dp);
    }
    
    int memo(int l, int r, int n, vector<vector<int>> &dp){
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r]; 
        int minValue = INT_MAX;
        for(int i = l; i <= r; ++i){
            minValue = min(minValue, i+max(memo(i+1, r, n, dp), memo(l, i-1, n, dp)));
        }
        dp[l][r] = minValue;
        return dp[l][r];
    }
};
