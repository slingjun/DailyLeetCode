class Solution {
public:
    int dp[1001][1001];
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return dfs(text1, text2, text1.length()-1, text2.length()-1);
    }
    
    int dfs(string &t1, string &t2, int i, int j){
        if(i == -1 || j == -1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = INT_MIN;
        if(t1[i] == t2[j]) 
            res = 1+dfs(t1,t2, i-1,j-1);
        else {
            res = max(dfs(t1,t2, i-1, j), dfs(t1,t2,i, j-1));
        }
        return dp[i][j] = res;
    }
};
