class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size());
        for(size_t i = 0; i < nums.size(); ++i){
            dp[i] = vector<int>(nums.size(), INT_MIN);
        }
        dfs(nums, 0, nums.size()-1, dp);
        return dp[0][nums.size()-1] >= 0;

    }
    
    int dfs(vector<int>& nums, int left, int right, vector<vector<int>> &dp){
        if(dp[left][right] != INT_MIN) return dp[left][right];
        if(left == right) {
            dp[left][right] = nums[left];
            return nums[left];
        }
        dp[left][right] =  max(nums[left]-dfs(nums,left+1, right, dp), nums[right]-dfs(nums, left, right-1, dp));
        return dp[left][right];
    }
};
