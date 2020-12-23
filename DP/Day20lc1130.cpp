class Solution {
public:
    int dp[41][41];
    int maxx[41][41];
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(int)*41*41);
        for(int i=0;i<arr.size();i++){
            maxx[i][i] = arr[i];
            for(int j=i+1;j<arr.size();j++)
                maxx[i][j] = max(maxx[i][j-1], arr[j]);
        }
        
        return dfs(arr, 0, arr.size()-1);
    }
    
    int dfs(vector<int>& arr, int l, int r){
        
        if(l >= r) return 0;
        if(dp[l][r]!=-1)  return dp[l][r];
        int minv = INT_MAX;
        for(int k = l; k < r; ++k){
            minv = min(minv, maxx[l][k]*maxx[k+1][r]+dfs(arr, l, k)+dfs(arr, k+1, r));
        }
        return dp[l][r] = minv;
    }
};
