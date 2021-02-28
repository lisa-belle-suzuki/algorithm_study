class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        dp = []
        dp.append([nums[0]])
        for i in range(1, len(nums)):
            num = nums[i]
            for j in range(len(dp)):
                if num > dp[j][-1]:
                    if len(dp[j]) == 2:
                        return True
                    dp.append(dp[j] + [num])
            dp.append([num])

        return False
