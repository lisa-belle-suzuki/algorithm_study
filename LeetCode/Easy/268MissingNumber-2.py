class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        max_ = len(nums)
        nums.sort()
        for i in range(max_):
            if nums[i] != i:
                return i
        return max_
