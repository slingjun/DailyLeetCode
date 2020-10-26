class Solution {
public: 
    //equivalent to the problem: partitioning the array into 4 groups with equal sum
    bool makesquare(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target % 2 != 0) return false;
        target /= 4;
        return dfs(nums, (int)nums.size(), 0, target, target, 4);
    }
    
    bool dfs(vector<int>& nums, int size, int index, int sum, int target, int k){
        // k == 4 in this problem
        if(k == 1) return true;
        if(target < 0 || index >= size) return false;
        bool result = false;
        for(int i = index; i < size; ++i){
            result = (target == 0) ? (result||dfs(nums, size, i+1, sum, sum, k-1))  
            : (result||dfs(nums, size, i+1, sum, target-nums[i], k));
        }
        return result;
    }
};
