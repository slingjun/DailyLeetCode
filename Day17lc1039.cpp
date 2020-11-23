class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int memo[50][50];
        memset(memo, -1, sizeof(int) * 50 * 50);
        return dp(A, 0, A.size()-1, memo);
    }
    
    int dp(vector<int>& A, int i, int j, int memo[50][50]){
        
        if(i == j-1) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int minv = INT_MAX;
        for(int k = i+1; k < j; ++k){
            minv = min(minv, dp(A, i, k, memo)+A[i]*A[k]*A[j]+dp(A, k, j,memo));
        }
        return memo[i][j] = minv;
    }
};
