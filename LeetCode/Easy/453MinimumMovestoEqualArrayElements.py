class Solution:
    def minMoves(self, nums: List[int]) -> int:
        min_num = float('inf')
        for i, num in enumerate(nums):
            if num < min_num:
                min_num = num
        for i, num in enumerate(nums):
            nums[i] -= min_num
        return sum(nums)
