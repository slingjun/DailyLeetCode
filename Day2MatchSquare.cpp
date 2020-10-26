class Solution {
public: 
    //equivalent to the problem: partitioning the array into 4 groups with equal sum
    bool makesquare(vector<int>& nums) {
        if(nums.size() == 0) return false;
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 4 != 0) return false;
        return dfs(nums,0,target/4, target/4, 4);
    }
    
    bool dfs(vector<int>& nums, int index, int sum, int target, int k){
        // k == 4 in this problem
        if(k == 0) return true;
        if(target < 0) return false;
        if(target == 0) return dfs(nums, 0, sum, sum, k-1);
        for(int i = index; i < nums.size(); ++i){
            if(nums[i]!=-2){
                int tmp = nums[i];
                nums[i] = -2;
                if(dfs(nums, i+1,sum,target-tmp, k)) return true;
                nums[i] = tmp;
            }
        }
        return false;
    }
};
