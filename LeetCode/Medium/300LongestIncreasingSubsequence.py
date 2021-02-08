class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        OFFSET = 10000
        dp = [ [0] * (10002+OFFSET) for _ in range(len(nums)+2) ]
        dp[0][nums[0]+OFFSET] = 1
        for i in range(1, len(nums)):
            cur = nums[i]
            max_so_far = 0
            for j in range(cur+OFFSET):
                dp[i][j] = dp[i-1][j]
                if dp[i-1][j] > max_so_far:
                    max_so_far = dp[i-1][j]
            dp[i][cur+OFFSET] = max_so_far + 1
            for j in range(cur+1+OFFSET, 10000 + 1 + OFFSET):
                dp[i][j] = dp[i-1][j]

        return max(dp[len(nums)-1])
