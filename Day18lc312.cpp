class Solution {
public:
    int dp[500][500];
    
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(int)*500*500);
        return dfs(nums, 0, nums.size()-1);
    }
    
    int dfs(vector<int> &nums, int start, int end){
        if(start>end||start<0||end>=nums.size()) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int maxv = INT_MIN;
        for(int i = start; i <= end; ++i){
            int left = 1, right = 1;
            if(start-1>=0) left=nums[start-1];
            if(end+1<nums.size()) right=nums[end+1];
            maxv=max(maxv,dfs(nums, start, i-1)+nums[i]*left*right+dfs(nums,i+1,end));
        }
        return dp[start][end] = maxv;
    }
};
