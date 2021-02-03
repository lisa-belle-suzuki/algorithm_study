class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort()

        if amount < 1:
            return 0

        dp = [float('inf')] * (amount + 2)
        dp[0] = 0

        for i in range(1, amount+1):
            cur_min = float('inf')
            for coin in coins:
                if 0<=i-coin<(amount+2):
                    if dp[i-coin] + 1 < cur_min:
                        cur_min = dp[i-coin] + 1
            dp[i] = cur_min

        if dp[amount] == float('inf'):
            return -1
        else:
            return dp[amount]
