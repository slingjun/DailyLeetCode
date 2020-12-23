class Solution {
public:
    bool canPartition(vector<int>& nums) { //01 knapsack
        int target = std::accumulate(nums.begin(), nums.end(), 0);
        if(target % 2 == 1) return false;
        target /= 2; //final target
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for(int &e : nums){
            for(size_t i = target; i > 0; --i){
                if(i >= e) dp[i] = dp[i]||dp[i-e]; 
            }
        }
        return dp[target];
    }
};
