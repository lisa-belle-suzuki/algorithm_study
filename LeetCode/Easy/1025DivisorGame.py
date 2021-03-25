class Solution:
    def divisorGame(self, N: int) -> bool:
        dp = [False] * (N+1)
        for i in range(2, N+1):
            cur = False
            for j in range(1, i):
                if i % j == 0:
                    if dp[i-j] == False:
                        cur = True
                        break
            dp[i] = cur
        return dp[N]
