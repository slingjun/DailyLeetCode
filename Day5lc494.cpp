class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(S > sum || (S+sum) % 2 != 0) return 0;
        int target = (S+sum)/2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(const int num : nums){
            for(int i = target; i >= num; --i){
                dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};
