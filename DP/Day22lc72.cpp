class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return dfs(word1,word2,word1.length()-1, word2.length()-1);
    }
    
    int dfs(string &w1, string &w2, int i, int j){
        if(i==-1)return j+1;
        if(j==-1)return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        int res = INT_MAX;
        if(w1[i] == w2[j]) {
            res = dfs(w1, w2, i-1, j-1);
        } else {
            res = min(dfs(w1, w2, i-1, j), min(dfs(w1,w2,i,j-1), dfs(w1,w2,i-1,j-1))) + 1; //delete | insert | replace
        }
        return dp[i][j] = res;
    }
};
