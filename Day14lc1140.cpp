class Solution {
public:
    int memo[101][101][2];
    int dp(int i,int p,int m,vector<int>& stones)
    {
        if(i>=stones.size())
            return 0;
        else if(memo[i][m][p]!=0)
            return memo[i][m][p];
        else
        {
            int val=0,q=(p==0?INT_MIN:INT_MAX),temp=0;
            for(int j=1;j<=2*m&&i+j<=stones.size();++j)
            {
                val+=stones[i+j-1];
                if(p==0)
                    q=max(q,val+dp(i+j,1,max(j,m),stones));
                else
                    q=min(q,dp(i+j,0,max(j,m),stones));
            }
            return memo[i][m][p]=q;
        }
    }
    int stoneGameII(vector<int>& piles)
	{
        return dp(0,0,1,piles);
    }
};
