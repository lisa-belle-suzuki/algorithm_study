class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        if x == 0 and y == 0:
            return 0
        l = max(abs(x), abs(y))
        s = min(abs(x), abs(y))
        dp = [[float('inf')] * (l+3) for _ in range(l+3)]
        dp[0][0] = 0
        dp[0][1] = 3
        dp[1][0] = 3
        dp[1][1] = 2

        def min_num(pairs) -> int:
            min_num = float('inf')
            for i, j in pairs:
                if i in range(l+3) and j in range(l+3):
                    min_num = min(min_num, dp[i][j])
            return min_num

        for i in range(l+3):
            for j in range(l+3):
                if dp[i][j] != float('inf'):
                    continue
                dp[i][j] = min_num([
                    (i-2, j-1), (i-1, j-2), (i+1, j-2), (i+2, j-1),
                    (i-2, j+1), (i-1, j+2), (i+1, j+2), (i+2, j+1)
                ]) + 1
        return dp[l][s]
