from pprint import pprint


class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        max_len = 0
        dp = [[0] * len(B) for _ in range(len(A))]
        for j in range(len(B)):
            if A[0] == B[j]:
                dp[0][j] = 1
        for i in range(len(A)):
            if A[i] == B[0]:
                dp[i][0] = 1
        for i in range(1, len(A)):
            for j in range(1, len(B)):
                if A[i] == B[j]:
                    cur_max = dp[i-1][j-1] + 1
                    max_len = max(cur_max, max_len)
                    dp[i][j] = cur_max

        return max_len
