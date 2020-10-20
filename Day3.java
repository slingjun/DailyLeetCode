class Solution {
    public int coinChange(int[] coins, int amount) {
        if (coins == null || coins.length == 0)
			return -1;
		if (amount <= 0)
			return 0;

		int dp[] = new int[amount + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
		for (int i = 0; i < coins.length; ++i) {
			for (int am = 1; am < dp.length; ++am) {
				if (coins[i] <= am && dp[am-coins[i]] != -1) {
					dp[am] = (dp[am] != -1) ? Math.min(dp[am-coins[i]] + 1, dp[am]) : dp[am-coins[i]]+1;
				}
			}
		}
		return dp[amount];
    }
}
