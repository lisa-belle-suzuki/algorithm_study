class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [[None] * 40000 for _ in range(len(nums)+1) ]

        for i in range(len(nums)):
            dp[i][0] = True

        for i, num in enumerate(nums):
            for j in range(1,len(dp[0])):
                if dp[i][j-num] is not None:
                    if dp[i][j-num]==True:
                        dp[i+1][j]=False
                if dp[i][j] is not None:
                    dp[i+1][j]=True

        ans = 0
        for s in range(len(dp[0])):
            cur = dp[len(nums)][s]
            if cur is not None:
                if s > ans:
                    ans = s
        return ans
