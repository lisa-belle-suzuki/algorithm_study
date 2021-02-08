class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        OFFSET = 10000
        dp = [0] * (10002+OFFSET)
        dp[nums[0]+OFFSET] = 1
        for i in range(1, len(nums)):
            cur = nums[i]
            max_so_far = max(dp[:cur+OFFSET])
            dp[cur+OFFSET] = max_so_far + 1
        return max(dp)
