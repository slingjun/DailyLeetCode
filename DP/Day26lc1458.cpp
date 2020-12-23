class Solution {
public:
    int dp[501][501];
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, 0, sizeof(dp));
        dfs(nums1, nums2, nums1.size(), nums2.size());
        return dp[nums1.size()][nums2.size()];

    }
    
    int dfs(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        dp[i][j] = nums1[i-1]*nums2[j-1]+max(dfs(nums1,nums2,i-1,j-1),0);
                if(j > 1)dp[i][j] = max(dp[i][j], dfs(nums1, nums2, i, j-1));
        if(i > 1)dp[i][j] = max(dp[i][j], dfs(nums1, nums2, i-1, j));
        return dp[i][j];
    }
};
