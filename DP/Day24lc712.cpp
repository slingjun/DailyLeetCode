class Solution {
public:
    int dp[1001][1001];
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return dfs(s1,s2,s1.length(), s2.length());
    }
    
    int dfs(string &s1, string &s2, int i, int j){
        if(i == 0 && j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0) return dp[i][j] = dfs(s1,s2,0,j-1)+97+s2[j-1]-'a';
        if(j == 0) return dp[i][j] = dfs(s1,s2,i-1,0)+97+s1[i-1]-'a';
        int res = INT_MAX;
        if(s1[i-1] != s2[j-1]) res = min(res, min(dfs(s1,s2,i-1,j)+97+s1[i-1]-'a', dfs(s1,s2,i,j-1)+97+s2[j-1]-'a'));
        else res = dfs(s1,s2,i-1,j-1);
        return dp[i][j] = res;
    }
};
