class Solution:
    def numSquares(self, n: int) -> int:
        perfect_square_nums = []
        dp = [float('inf')] * 10001

        i = 1
        while i * i <= 10000:
            perfect_square_nums.append(i*i)
            i += 1

        dp[0] = 0
        for i in range(1, n+1):
            min_num = float('inf')
            for square in perfect_square_nums:
                if square > n: break
                min_num = min(min_num, dp[i-square] + 1)
            dp[i] = min_num

        return dp[n]
