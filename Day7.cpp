class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int target = accumulate(rods.begin(), rods.end(), 0);
        vector<bool> dp(target+1, false);
        vector<int>  dp2(target+1, 0);
        dp[0] = false;
        for(size_t i = 0; i < rods.size(); ++i){
            for(int j = target; j >= rods[i]; --j){
                dp[j] = dp[j] || dp[j-rods[i]];
                if(dp[j]) dp2[j]++;
            }
        }
        int i = (target%2 == 1) ? target-1 : target;
        for(;i>0; i-=2){
            if(dp2[i] > 1) return i/2;
        }
        return 0;
    }
};
