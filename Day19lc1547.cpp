class Solution {
public:
    int dp[102][102];  //102 because we add the 0 and n into the cache
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(int)*102*102);
        return dfs(cuts, 0, cuts.size()-1);
    }
    
    int dfs(vector<int>& cuts, int start, int end){ //memorize the min between cuts[i] anad cuts[j], denoted by dp[start][end]
        if(end - start <= 1) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int res = INT_MAX;
        for(int i = start+1; i < end; ++i){
            res = min(res, cuts[end]-cuts[start]+dfs(cuts, start, i)+dfs(cuts, i, end));
        }
        return dp[start][end] = res;
    }
};
