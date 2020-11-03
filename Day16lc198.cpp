class Solution {
public:
    int memo[100];
    int rob(vector<int>& nums) {
        for(int i = 0; i < 100; ++i) memo[i] = -1;
        return dp(nums, 0);
    }
    
    int dp(vector<int> &nums, int start){
        if(start >= nums.size()) return 0;
        if(memo[start] != -1) return memo[start];
        int res = INT_MIN;
        for(int i = start; i < nums.size(); i+=2){
            res = max(res, nums[start]+dp(nums, i+2));
            res = max(res, dp(nums,start+1));
        }
        return memo[start] = res;
    }
};
