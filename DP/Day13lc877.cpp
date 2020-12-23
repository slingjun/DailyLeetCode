class Solution {
public:
    bool stoneGame(vector<int>& piles) { // similar to predict the winner
        vector<vector<int>> memo(piles.size()+1);
        for(size_t i = 0; i < memo.size(); ++i){
            memo[i] = vector<int>(piles.size()+1, INT_MIN);
        }
        return dp(piles, 0, piles.size()-1, memo) > 0;
    }
    
    int dp(vector<int> &piles, int l, int r, vector<vector<int>> &memo){
        if(memo[l][r] != INT_MIN) return memo[l][r];
        if(l == r) return memo[l][r] = piles[r];
        if(l > r) return 0;
        memo[l][r] = max(piles[l]-dp(piles, l+1, r, memo), piles[r]-dp(piles, l, r-1, memo));
        return memo[l][r];
    }
};
