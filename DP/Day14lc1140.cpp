class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        return dp(piles, 0, 1, 0);
    }
    
    int dp(vector<int> &piles, int start, int m, int player){//player0: me; player1: other

        if(start >=piles.size()) return 0;
        if(memo[start][m][player]!=0) return memo[start][m][player];
        int end = start+2*m;
        int accumulate = 0; // a running total
        int tmp = (player == 0) ? INT_MIN : INT_MAX;
        for(int i = start; i < end && i < piles.size(); ++i){
            accumulate += piles[i]; //record the stone amount before the next start
            if(player == 0){
                tmp = max(tmp, accumulate+dp(piles, i+1, max(i-start+1, m), 1)); // note i-start+1 is the X where 1<=X<=2m
            }else{
                tmp = min(tmp, dp(piles, i+1, max(i-start+1, m), 0)); //player 2 wants to minimize my stone count
            }
        }
        memo[start][m][player] = tmp;
        return tmp;
    }
private:
    int memo[101][101][2];
};
