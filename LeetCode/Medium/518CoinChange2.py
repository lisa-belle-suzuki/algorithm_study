class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # DP
        if amount == 0:
            return 1
        if len(coins) == 0:
            return 0
        dp = [[0] * (amount+1) for _ in range(len(coins))]
        for i in range(len(coins)):
            if i == 0:
                for k in range(amount//coins[i]+1):
                    dp[i][coins[0]*k] = 1
                continue
            for j in range(amount+1):
                for k in range(j//coins[i]+1):
                    dp[i][j] += dp[i-1][j-coins[i]*k]

        return dp[len(coins)-1][amount]
