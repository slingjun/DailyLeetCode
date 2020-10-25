class Solution {
    //2,7,4,1,8,1       sum = 23
    //4-2 [2,7,1,8,1]
    //8-7 [2,1,1,1] :: 8-7-1
    //2-1 [1,1,1] :: 4-2-1
    //1-1 [1]:: (4-2-1)+(8-7-1) = (4+8)-(2+1+1+7) = 1
    // two groups with smallest difference, i.e. min(S1-S2)
    // S2 = sum-S1, what we want is abs(min(2S1-sum));
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(),0);
        vector<bool> dp(sum/2,false);
        dp[0] = true;
        for(const int num : stones){
            for(int j = sum/2; j >= num; --j){
                dp[j] = dp[j] || dp[j-num];
            }
        }
        for(int i = sum/2; i >= 0; --i){
            if(dp[i]) return sum-2*i;
        }
        return 0;
    }
};
