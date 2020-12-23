class Solution {
public:
    int dp[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
        memset(dp, -1,sizeof(dp));
        return dfs(s1,s2,s3, s1.length(), s2.length(), s3.length());
    }
    
    bool dfs(string &s1, string &s2, string& s3, int i, int j, int k) {
        if(i == 0 && j == 0) return true;
        if(dp[i][j] != -1) return dp[i][j]; 
        bool res = false;
        if(i!= 0 && s1[i-1] == s3[k-1]) res = dfs(s1,s2,s3,i-1,j,k-1);
        if(j != 0 && s2[j-1] == s3[k-1]) res = res || dfs(s1,s2,s3,i, j-1, k-1);
        return dp[i][j] = res;
    }
};
